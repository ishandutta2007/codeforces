#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

int x[3], y[3];

vector <pair <pii, pii>> vans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    For(i, 0, 3){
        cin >> x[i] >> y[i];
    }

    vi vx(x, x + 3);
    sort(bend(vx));
    vi vy(y, y + 3);
    sort(bend(vy));
    if (vx[0] != vx[2]){
        vans.emplace_back(make_pair(vx[0], vy[1]), make_pair(vx[2], vy[1]));
    }
    For(i, 0, 3){
        if (y[i] != vy[1]){
            vans.emplace_back(make_pair(x[i], y[i]), make_pair(x[i], vy[1]));
        }
    }
    cout << isz(vans) << endl;
    Fora(elem, vans){
        cout << elem.fi.fi << ' ' << elem.fi.se << ' ' << elem.se.fi << ' ' << elem.se.se << endl;
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/