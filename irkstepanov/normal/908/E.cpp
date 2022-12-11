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

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

int binpow(int a, int n) {
    int ans = 1;
    assert(a != 0);
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

const int nmax = 1050;

int stirl[nmax][nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    stirl[0][0] = 1;
    for (int n = 1; n < nmax; ++n) {
        for (int k = 1; k <= n; ++k) {
            stirl[n][k] = stirl[n - 1][k - 1];
            int val = k;
            mul(val, stirl[n - 1][k]);
            add(stirl[n][k], val);
        }
    }

    int m, n;
    cin >> m >> n;

    vector<vector<int> > v;
    v.pb(vector<int>());
    for (int i = 0; i < m; ++i) {
        v.back().pb(i);
    }

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vector<vector<int> > nx;
        for (int j = 0; j < sz(v); ++j) {
            /*for (int x : v[j]) {
                cout << x << " ";
            }
            cout << endl;*/
            int ptr = 0;
            vector<int> curr;
            for (int pos = 0; pos < m; ++pos) {
                if (v[j][ptr] < pos) {
                    ++ptr;
                }
                if (ptr == sz(v[j])) {
                    break;
                }
                if (v[j][ptr] == pos && s[pos] == '1') {
                    curr.pb(pos);
                }
            }
            if (sz(curr) == sz(v[j]) || curr.empty()) {
                nx.pb(v[j]);
            } else {
                vector<int> comp;
                ptr = 0;
                for (int val : curr) {
                    while (v[j][ptr] != val) {
                        comp.pb(v[j][ptr]);
                        ++ptr;
                    }
                    ++ptr;
                }
                while (ptr < sz(v[j])) {
                    comp.pb(v[j][ptr]);
                    ++ptr;
                }
                nx.pb(curr);
                nx.pb(comp);
            }
        }
        //cout << endl;
        v.swap(nx);
    }

    /*for (int j = 0; j < sz(v); ++j) {
        for (int x : v[j]) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    int ans = 1;
    for (int i = 0; i < sz(v); ++i) {
        int s = sz(v[i]);
        int sum = 0;
        for (int k = 1; k <= s; ++k) {
            int val = stirl[s][k];
            //cout << s << " " << k << " " << val << "\n";
            add(sum, val);
        }
        mul(ans, sum);
    }

    cout << ans << "\n";

}