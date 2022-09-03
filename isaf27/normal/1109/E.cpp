/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 1e9 + 239;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = 1e5 + 239;
const int N = 2e3 + 239;
const int L = 12;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 2e6 + 239;

ll gcd(ll x, ll y)
{
	return (x ? gcd(y % x, x) : y);
}

ll inv(ll a, ll m)
{
	if (a == 1)
		return 1;
	return ((1 - inv(m % a, a) * m) / a) + m;
}

int n, m, p[L], c, sx[L];
int v[L][T], av[L][T], sum[T], add[T];

void build(int i, int l, int r)
{
    for (int x = 0; x < c; x++)
    {
        v[x][i] = 0;
        av[x][i] = 0;
    }
    add[i] = 1;
    if (r - l == 1)
    {
        sum[i] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
    if (sum[i] >= m) sum[i] -= m;
}

void push(int i, int l, int r)
{
    for (int x = 0; x < c; x++)
        v[x][i] += av[x][i];
    sum[i] = ((ll)sum[i] * (ll)add[i]) % (ll)m;
    if (r - l != 1)
    {
        for (int x = 0; x < c; x++)
        {
            av[x][2 * i + 1] += av[x][i];
            av[x][2 * i + 2] += av[x][i];
        }
        add[2 * i + 1] = ((ll)add[2 * i + 1] * (ll)add[i]) % (ll)m;
        add[2 * i + 2] = ((ll)add[2 * i + 2] * (ll)add[i]) % (ll)m;
    }
    add[i] = 1;
    for (int x = 0; x < c; x++)
        av[x][i] = 0;
}

void upd(int i, int l, int r, int ql, int qr, int um)
{
    push(i, l, r);
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr)
    {
        for (int x = 0; x < c; x++)
            av[x][i] += sx[x];
        add[i] = ((ll)add[i] * (ll)um) % (ll)m;
        push(i, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    upd(2 * i + 1, l, mid, ql, qr, um);
    upd(2 * i + 2, mid, r, ql, qr, um);
    for (int x = 0; x < c; x++)
        v[x][i] = v[x][2 * i + 1] + v[x][2 * i + 2];
    sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
    if (sum[i] >= m) sum[i] -= m;
}

void change(int i, int l, int r, int p, int x)
{
    push(i, l, r);
    if (p < l || r <= p) return;
    if (r - l == 1)
    {
        for (int x = 0; x < c; x++)
            v[x][i] = sx[x];
        sum[i] = x;
        return;
    }
    int mid = (l + r) >> 1;
    change(2 * i + 1, l, mid, p, x);
    change(2 * i + 2, mid, r, p, x);
    for (int x = 0; x < c; x++)
        v[x][i] = v[x][2 * i + 1] + v[x][2 * i + 2];
    sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
    if (sum[i] >= m) sum[i] -= m;
}

int getsum(int i, int l, int r, int ql, int qr)
{
    push(i, l, r);
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return sum[i];
    int mid = (l + r) >> 1;
    int ans = getsum(2 * i + 1, l, mid, ql, qr) + getsum(2 * i + 2, mid, r, ql, qr);
    if (ans >= m) ans -= m;
    return ans;
}

void fndpw(int i, int l, int r, int p)
{
    push(i, l, r);
    if (p < l || r <= p) return;
    if (r - l == 1)
    {
        for (int x = 0; x < c; x++)
            sx[x] = v[x][i];
        return;
    }
    int mid = (l + r) >> 1;
    fndpw(2 * i + 1, l, mid, p);
    fndpw(2 * i + 2, mid, r, p);
}

int pr[T], ap[T];

void push_vs(int i, int l, int r)
{
    pr[i] = ((ll)pr[i] * (ll)ap[i]) % (ll)m;
    if (r - l != 1)
    {
        ap[2 * i + 1] = ((ll)ap[2 * i + 1] * (ll)ap[i]) % (ll)m;
        ap[2 * i + 2] = ((ll)ap[2 * i + 2] * (ll)ap[i]) % (ll)m;
    }
    ap[i] = 1;
}

void build_vs(int i, int l, int r)
{
    ap[i] = 1;
    if (r - l == 1)
    {
        pr[i] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build_vs(2 * i + 1, l, mid);
    build_vs(2 * i + 2, mid, r);
    pr[i] = pr[2 * i + 1] + pr[2 * i + 2];
    if (pr[i] >= m) pr[i] -= m;
}

void upd_vs(int i, int l, int r, int ql, int qr, int um)
{
    push_vs(i, l, r);
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr)
    {
        ap[i] = ((ll)ap[i] * (ll)um) % (ll)m;
        push_vs(i, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    upd_vs(2 * i + 1, l, mid, ql, qr, um);
    upd_vs(2 * i + 2, mid, r, ql, qr, um);
    pr[i] = pr[2 * i + 1] + pr[2 * i + 2];
    if (pr[i] >= m) pr[i] -= m;
}

int getvs(int i, int l, int r, int p)
{
    push_vs(i, l, r);
    if (r - l == 1) return pr[i];
    int mid = (l + r) >> 1;
    if (p < mid)
        return getvs(2 * i + 1, l, mid, p);
    else
        return getvs(2 * i + 2, mid, r, p);
}

int rt[L];
int pw[L][X];

int32_t main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    c = 0;
    int mm = m;
    for (int i = 2; i * i <= m; i++)
        if (mm % i == 0)
        {
            p[c++] = i;
            while (mm % i == 0)
                mm /= i;
        }
    if (mm > 1)
        p[c++] = mm;
    /*cerr << c << "\n";
    for (int x = 0; x < c; x++)
        cerr << p[x] << " ";
    cerr << "\n";*/
    for (int i = 0; i < c; i++)
    {
        pw[i][0] = 1;
        for (int j = 1; j < X; j++)
            pw[i][j] = ((ll)pw[i][j - 1] * (ll)p[i]) % (ll)m;
    }
    build(0, 0, n);
    build_vs(0, 0, n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int aa = a;
        for (int x = 0; x < c; x++)
        {
            sx[x] = 0;
            while (a % p[x] == 0)
            {
                sx[x]++;
                a /= p[x];
            }
            //cerr << sx[x] << " ";
        }
        //cerr << "\n";
        //cerr << a << "\n";
        change(0, 0, n, i, aa);
        upd_vs(0, 0, n, i, i + 1, a);
    }
    /*cerr << "\n";
    for (int i = 0; i < n; i++)
        cerr << getsum(0, 0, n, i, i + 1) << "\n";*/
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int tp, l, r, t;
        cin >> tp;
        if (tp == 1)
        {
            cin >> l >> r >> t;
            l--, r--;
            int tt = t;
            for (int x = 0; x < c; x++)
            {
                sx[x] = 0;
                while (t % p[x] == 0)
                {
                    sx[x]++;
                    t /= p[x];
                }
            }
            upd(0, 0, n, l, r + 1, tt);
            upd_vs(0, 0, n, l, r + 1, t);
        }
        else if (tp == 2)
        {
            cin >> l >> t;
            l--;
            fndpw(0, 0, n, l);
            int u = getvs(0, 0, n, l);
            for (int x = 0; x < c; x++)
                while (t % p[x] == 0)
                {
                    sx[x]--;
                    t /= p[x];
                }
            t = inv(t, m);
            upd_vs(0, 0, n, l, l + 1, t);
            u = ((ll)u * (ll)t) % (ll)m;
            for (int x = 0; x < c; x++)
                u = ((ll)u * (ll)pw[x][sx[x]]) % (ll)m;
            change(0, 0, n, l, u);
        }
        else
        {
            cin >> l >> r;
            l--, r--;
            cout << getsum(0, 0, n, l, r + 1) << "\n";
        }
    }
    return 0;
}