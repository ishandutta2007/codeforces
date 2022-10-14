#include <iostream>
#include <assert.h>
#include <bitset>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <array>
using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)


const int mxN = 1e5 + 2;
int n, m;
bool ok = true;
vector<pair<int, int>> adj[mxN];
// k*a+c
pair<int, int> eqs[mxN];
bitset<mxN> visited;
int values[mxN];
array<int,mxN> medians;
int dfs(int begin) {
    eqs[begin] = { 1,0 };
    visited[begin] = true;
    stack<int> s;
    s.push(begin);
    int a=-100000;
    bool afound = false;
    int cnt = 1;
    medians[0] = 0;
    while (!s.empty()) {
        int at = s.top(); s.pop();
        for (auto p : adj[at]) {
            int to, red;
            tie(to, red) = p;
            //cout << to << ' ' << red << endl;
            if (!visited[to]) {
                int tmp = -eqs[at].first, tmp2 = red - eqs[at].second;
                medians[cnt++] = 2*tmp * tmp2;
                visited[to] = true;
                eqs[to] = { tmp, tmp2 };
                s.push(to);
            } else {
                int mya = -eqs[at].first, myc = red - eqs[at].second;
                if (mya == eqs[to].first) {
                    if (myc != eqs[to].second) {
                        ok = false;
                        return -1;
                    }
                }
                else {
                    int myans = (eqs[to].second- myc) * (mya - eqs[to].first) / 2;
                    if (afound) {
                        if (myans != a) {
                            ok = false;
                            return -1;
                        }
                    }
                    else {
                        a = myans;
                        afound = true;
                    }
                }
            }
        }
    }
    if (afound) return a;
    sort(medians.begin(), medians.begin()+cnt);
    return -medians[cnt / 2];
}
void fillgraph(int at, const int a) {
    visited[at] = true;
    values[at] = a * eqs[at].first + 2 * eqs[at].second;
    for (auto p : adj[at]) {
        if (!visited[p.first]) {
            fillgraph(p.first, a);
        }
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    unordered_map<int, int> attoa;

    for (int i = 1; i <= n and ok; ++i) {
        if (!visited[i]) attoa[i] = dfs(i);
    }
    if (!ok) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        visited.reset();
        for (auto& p : attoa) {
            fillgraph(p.first, p.second);
        }
        for (int i = 1; i <= n;++i) {
            cout << values[i] / 2.0 << endl;
        }
    }

}