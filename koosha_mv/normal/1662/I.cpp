/* Im the best and i work like that */

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

#define F first
#define S second
#define all(x) x.begin(),x.end()
#define Mp make_pair
#define point complex
#define endl '\n'
#define SZ(x) (int)x.size()
#define fast_io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file_io freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define mashtali return cout << "Hello, World!", 0;
#define int ll

const int N = 1e6 + 10;
const int LOG = 20;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const double pi = acos(-1);
const ld eps = 1e-18;
const ld one = 1.;

ll pw(ll a, ll b, ll M, ll ret = 1) { if(a == 0) return 0; a %= M; while(b) { ret = (b & 1? ret * a % M : ret), a = a * a % M, b >>= 1; } return ret % M; }

mt19937 rng(time(nullptr));

int n, m, C[N], A[N];

ll ps[N];

int32_t main()
{
	fast_io;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> C[i];
        ps[i] = ps[i - 1] + C[i];
    }
    for(int i = 1; i <= m; i ++)
    {
        cin >> A[i];
    }
    sort(A + 1, A + m + 1);
    A[0] = -inf;
    A[m + 1] = inf;
    int tot = 0;
    for(int i = 1; i <= n; i ++)
    {
        int pos = (i - 1) * 100;
        int nxt = lower_bound(A, A + m + 2, pos) - A;
        if(A[nxt] == pos) continue;
        int prv = nxt - 1;
        int del = pos - A[prv];
        int R = min(pos + del, A[nxt]);
        del = A[nxt] - R;
        ll X = (del + 1) / 2 - 1;
        ll Pos = R + X;
        int ID = min(n, (Pos / 100) + 1);
        tot = max(tot, ps[ID] - ps[i - 1]);
    }
    cout << tot;
	return 0;
}

/* check corner case(n = 1?), watch for negetive index or overflow */