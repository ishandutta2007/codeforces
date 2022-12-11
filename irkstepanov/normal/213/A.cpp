#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<vector<int> > gr, g;
const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int n;
    cin >> n;
    vector<int> color(n);
    for (int i = 0; i < n; ++i) {
        cin >> color[i];
        --color[i];
    }

    gr.resize(n);
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int j;
            cin >> j;
            --j;
            gr[i].pb(j);
            g[j].pb(i);
        }
    }

    int ans = inf;

    for (int st = 0; st < 3; ++st) {
        int curr = st;
        int res = 0;
        int put = 0;
        vector<int> deg(n);
        for (int i = 0; i < n; ++i) {
            deg[i] = sz(gr[i]);
        }
        vector<bool> used(n, false);
        while (put < n) {
            int v = -1;
            for (int i = 0; i < n; ++i) {
                if (!used[i] && color[i] == curr && deg[i] == 0) {
                    v = i;
                    break;
                }
            }
            if (v == -1) {
                curr = (curr + 1) % 3;
                ++res;
                continue;
            }
            used[v] = true;
            for (int to : g[v]) {
                --deg[to];
            }
            ++res;
            ++put;
        }
        ans = min(ans, res);
    }

    cout << ans << "\n";

}