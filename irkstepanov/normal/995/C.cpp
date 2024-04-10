#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

struct pt {
    ll x, y;
    int id;
    pt() {}
    pt(ll x, ll y, int id = -1) : x(x), y(y), id(id) {}
    ll len() const {
        return x * x + y * y;
    }
    pt operator+(const pt& other) const {
        return {x + other.x, y + other.y};
    }
    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }
};

ll K = ll(1e12);

mt19937 rr(12);

void rs(vector<pt>& v) {
    for (int i = 1; i < sz(v); ++i) {
        int j = rr() % (i + 1);
        swap(v[i], v[j]);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //cout << K << endl;

    int n;
    cin >> n;

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }

    vector<pt> curr = p;
    vector<vector<int> > cont(n);
    int k = n;

    while (sz(curr) > 1) {
        if (sz(curr) == 2) {
            K /= 4;
            K *= 9;
        }
        rs(curr);
        vector<pt> nx;
        for (int i = 0; i < sz(curr); i += 2) {
            if (i + 1 == sz(curr)) {
                nx.pb(curr[i]);
                break;
            }
            pt a = curr[i], b = curr[i + 1];
            if ((a + b).len() <= K) {
                pt z = a + b;
                z.id = k++;
                nx.pb(z);
                cont.pb({a.id, 1, b.id, 1});
                continue;
            }
            if ((a - b).len() <= K) {
                pt z = a - b;
                z.id = k++;
                nx.pb(z);
                cont.pb({a.id, 1, b.id, -1});
                continue;
            }
            nx.pb(a);
            nx.pb(b);
        }
        curr.swap(nx);
    }

    vector<int> ans(k);
    ans.back() = 1;
    for (int u = k - 1; u >= 0; --u) {
        //cout << u << ": ";
        for (int i = 0; i < sz(cont[u]); i += 2) {
            int x = cont[u][i];
            //cout << x << " " << cont[u][i + 1] << "; ";
            ans[x] = ans[u] * cont[u][i + 1];
        }
        //cout << "\n";
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}