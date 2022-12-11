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
typedef long double ld;
typedef pair<ll, ll> pll;

const int buben = 5;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    set<vector<int> > s;
    map<vector<int>, vector<int> > mapa;
    queue<vector<int> > q;
    vector<int> v = {1, 1, 1, 1};
    q.push(v);
    s.insert(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            vector<int> nx = v;
            if (nx[i] > 1 && nx[(i + 1) % 4] > 1) {
                --nx[i];
                --nx[(i + 1) % 4];
                if (!s.count(nx)) {
                    mapa[nx] = v;
                    s.insert(nx);
                    q.push(nx);
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            vector<int> nx = v;
            nx[i] *= 2;
            nx[(i + 1) % 4] *= 2;
            if (nx[i] >= 2 * buben || nx[(i + 1) % 4] >= 2 * buben) {
                continue;
            }
            if (!s.count(nx)) {
                mapa[nx] = v;
                s.insert(nx);
                q.push(nx);
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        cin >> v[i];
    }

    while (true) {
        int i0 = -1;
        for (int i = 0; i < 4; ++i) {
            if (v[i] > buben) {
                i0 = i;
            }
        }
        if (i0 == -1) {
            break;
        }
        if (v[i0] % 2 != v[(i0 + 1) % 4] % 2) {
            cout << "+" << (i0 + 1) % 4 + 1 << "\n";
            ++v[(i0 + 1) % 4];
            ++v[(i0 + 2) % 4];
        }
        if (v[i0] % 2) {
            cout << "+" << i0 + 1 << "\n";
            ++v[i0];
            ++v[(i0 + 1) % 4];
        }
        cout << "/" << i0 + 1 << "\n";
        v[i0] /= 2;
        v[(i0 + 1) % 4] /= 2;
    }

    /*for (int i = 0; i < 4; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;*/

    while (v[0] != 1 || v[1] != 1 || v[2] != 1 || v[3] != 1) {
        vector<int> u = mapa[v];

        bool done = false;
        for (int i = 0; i < 4; ++i) {
            ++v[i];
            ++v[(i + 1) % 4];
            if (v == u) {
                cout << "+" << i + 1 << "\n";
                done = true;
                break;
            }
            --v[i];
            --v[(i + 1) % 4];
        }
        if (done) {
            v = u;
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            if (v[i] % 2 == 0 && v[(i + 1) % 4] % 2 == 0) {
                v[i] /= 2;
                v[(i + 1) % 4] /= 2;
                if (v == u) {
                    cout << "/" << i + 1 << "\n";
                    done = true;
                    break;
                }
                v[i] *= 2;
                v[(i + 1) % 4] *= 2;
            }
        }
        assert(done);
        v = u;
    }

}