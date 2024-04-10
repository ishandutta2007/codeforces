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

const int N = 1500 + 5;

int n;
int a[N][N];

pii pos[N * N];
int cntrow[N], cntcol[N];

ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        ForE(j, 1, n){
            cin >> a[i][j];
        }
    }

    ForE(i, 1, n){
        ForE(j, 1, n){
            pos[a[i][j]] = make_pair(i, j);
        }
    }
    ForE(val, 1, n * n){
        int i, j; tie(i, j) = pos[val];
        ans += (ll)cntrow[i] * (n - 1 - cntcol[j]);
        ans += (ll)(n - 1 - cntrow[i]) * cntcol[j];
        cntrow[i]++; cntcol[j]++;
    }
    cout << ans / 2 << endl;
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