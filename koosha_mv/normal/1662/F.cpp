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

const int N = 1e6 + 10;
const int LOG = 20;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const double pi = acos(-1);
const ld eps = 1e-18;
const ld one = 1.;

ll pw(ll a, ll b, ll M, ll ret = 1) { if(a == 0) return 0; a %= M; while(b) { ret = (b & 1? ret * a % M : ret), a = a * a % M, b >>= 1; } return ret % M; }

mt19937 rng(time(nullptr));

pii Mn[N << 2], Mx[N << 2];

int n, st, fi, A[N], dis[N];

void build(int v = 1, int tl = 1, int tr = n)
{
    if(tl == tr)
    {
        Mn[v] = Mp(tl - A[tl], tl);
        Mx[v] = Mp(tl + A[tl], tl);
        return;
    }
    int mid = (tl + tr) >> 1;
    build(v << 1, tl, mid), build(v << 1 | 1, mid + 1, tr);
    Mn[v] = min(Mn[v << 1], Mn[v << 1 | 1]);
    Mx[v] = max(Mx[v << 1], Mx[v << 1 | 1]);
}

void upd(int p, int v = 1, int tl = 1, int tr = n)
{
    if(tl == tr)
    {
        Mn[v] = Mp(inf, -1);
        Mx[v] = Mp(-inf, -1);
        return;
    }
    int mid = (tl + tr) >> 1;
    if(p <= mid) upd(p, v << 1, tl, mid);
    else upd(p, v << 1 | 1, mid + 1, tr);
    Mn[v] = min(Mn[v << 1], Mn[v << 1 | 1]);
    Mx[v] = max(Mx[v << 1], Mx[v << 1 | 1]);
}

pii get(int l, int r, int v = 1, int tl = 1, int tr = n)
{
    if(l > tr || r < tl || l > r)
    {
        return Mp(inf, -1);
    }
    if(l <= tl && tr <= r)
    {
        return Mn[v];
    }
    int mid = (tl + tr) >> 1;
    return min(get(l, r, v << 1, tl, mid), get(l, r, v << 1 | 1, mid + 1, tr));
}

pii GET(int l, int r, int v = 1, int tl = 1, int tr = n)
{
    if(l > tr || r < tl || l > r)
    {
        return Mp(-inf, -1);
    }
    if(l <= tl && tr <= r) return Mx[v];
    int mid = (tl + tr) >> 1;
    return max(GET(l, r, v << 1, tl, mid), GET(l, r, v << 1 | 1, mid + 1, tr));
}

void solve()
{
    cin >> n >> st >> fi;
    for(int i = 1; i <= n; i ++)
    {
        dis[i] = 1e9;
        cin >> A[i];
    }
    build();
    deque < int > dq;
    dq.push_back(st);
    dis[st] = 0;
    upd(st);
    while(SZ(dq))
    {
        int v = dq.front();
        dq.pop_front();
        int r = min(n, v + A[v]);
        int l = max(1, v - A[v]);
        pii cu;
        while(1)
        {
            cu = get(v, r);
            if(cu.S == -1 || cu.F > v) break;
            dis[cu.S] = dis[v] + 1;
            dq.push_back(cu.S);
            upd(cu.S);
        }
        while(1)
        {
            cu = GET(l, v);
            if(cu.S == -1 || cu.F < v) break;
            dis[cu.S] = dis[v] + 1;
            dq.push_back(cu.S);
            upd(cu.S);
        }
    }
    cout << dis[fi] << endl;
}

int main()
{
	fast_io;
    int q;
    cin >> q;
    while(q --)
    {
        solve();
    }
	return 0;
}

/* check corner case(n = 1?), watch for negetive index or overflow */