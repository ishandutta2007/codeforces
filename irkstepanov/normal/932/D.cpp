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
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int rmax = 22;

vector<ll> w;
vector<vector<int> > parent, wh;
vector<vector<ll> > sum, maxx;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    w.pb(0);
    parent.pb(vector<int>(rmax, 0));
    wh.pb(vector<int>(rmax, -1));
    sum.pb(vector<ll>(rmax, -1));
    maxx.pb(vector<ll>(rmax, 0));
    ll last = 0;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll p, q;
            cin >> p >> q;
            ll v = p ^ last;
            ll cost = q ^ last;
            --v;
            w.pb(cost);
            parent.pb(vector<int>(rmax));
            parent.back()[0] = v;
            maxx.pb(vector<ll>(rmax));
            maxx.back()[0] = w[v];
            v = sz(parent) - 1;
            for (int r = 0; r + 1 < rmax; ++r) {
                int t = parent[v][r];
                parent[v][r + 1] = parent[t][r];
                maxx[v][r + 1] = max(maxx[v][r], maxx[t][r]);
            }
            if (maxx[v][rmax - 1] < w[v]) {
                wh.pb(vector<int>(rmax, -1));
                sum.pb(vector<ll>(rmax, -1));
                continue;
            }
            int curr = v;
            for (int r = rmax - 1; r >= 0; --r) {
                if (maxx[curr][r] < w[v]) {
                    curr = parent[curr][r];
                }
            }
            curr = parent[curr][0];
            assert(w[curr] >= w[v]);
            wh.pb(vector<int>(rmax));
            sum.pb(vector<ll>(rmax));
            wh[v][0] = curr;
            sum[v][0] = w[curr];
            for (int r = 0; r + 1 < rmax; ++r) {
                int t = wh[v][r];
                if (t == -1 || wh[t][r] == -1) {
                    wh[v][r + 1] = -1;
                    sum[v][r + 1] = -1;
                } else {
                    wh[v][r + 1] = wh[t][r];
                    sum[v][r + 1] = sum[v][r] + sum[t][r];
                }
            }
        } else {
            ll p, q;
            cin >> p >> q;
            ll v = p ^ last;
            ll x = q ^ last;
            --v;
            if (w[v] > x) {
                cout << "0\n";
                last = 0;
                continue;
            }
            int ans = 1;
            x -= w[v];
            //cout << "!" << wh[v][0] << " " << sum[v][0] << endl;
            for (int r = rmax - 1; r >= 0; --r) {
                if (wh[v][r] == -1) {
                    continue;
                }
                if (sum[v][r] > x) {
                    continue;
                }
                //cout << "D" << endl;
                x -= sum[v][r];
                v = wh[v][r];
                ans += (1 << r);
            }
            cout << ans << "\n";
            last = ans;
        }
    }

}