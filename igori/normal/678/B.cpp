//Updated 29.09.18
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <bitset>
using namespace std;
#define sqr(z) (z) * (z)
#define ch_NO(x) cout << "NO\n"; x = 1 - x;
#define b_NO cout << "NO\n"; break;
#define r_NO cout << "NO\n"; return 0;
#define c_NO cout << "NO\n"; continue;
#define ch_YES(x) cout << "YES\n"; x = 1 - x;
#define b_YES cout << "YES\n"; break;
#define r_YES cout << "YES\n"; return 0;
#define c_YES cout << "YES\n"; continue;
#define sz size()
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
#define mm(k) memset((k), -1, sizeof(k));
#define all(k) (k).begin(), (k).end()
#define forn(i, n) for (int (i) = 0; (i) != (n); i++)
#define nfor(i, n) for (int (i) = (n) - 1; (i) != -1; i--)
#define do_nothing cout << " Work_Error ";
#define erace erase
#define incert insert
#define reverce reverse
#define re return
#define prev prev1234
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> lpii;
typedef unsigned long long ull;
#define int long long
const int INF = 1e9;
const ll INFLL = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
const double PI = 3.14159265358979323846264338327;
ll inq(ll k, ll q, ll mod)
{
    if (q == 0)
        return 1;
    ll l = inq(k, q / 2, mod);
    if (q % 2 == 0)
        return l * l % mod;
    else
        return l * l % mod * k % mod;
}
ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll cubr(ll a)
{
    ll l = -1, r = 1e6 + 2;
    while (l < r - 1)
    {
        ll mid = (l + r) / 2;
        if (mid * mid * mid > a)
            r = mid;
        else
            l = mid;
    }
    return l;
}
ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll min(ll a, ll b)
{
    return -1 * max(-a, -b);
}
ll possible(ll q)
{
    if (q == INF)
        return -1;
    return q;
}
bool correct(int x, int xx)
{
    if (x < 0)
        return 0;
    if (x >= xx)
        return 0;
    return 1;
}
ll dsumm(ll x, ll k)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; y < 1e18; i++)
    {
        z += x / y % k;
        y *= k;
    }
    return z;
}
ll dcount(ll x)
{
    ll y = 1;
    ll z = 0;
    int c[100];
    for (int i = 0; i < 10; i++)
    c[i] = 0;
    for (int i = 0; x > 0; i++)
    {
        if (c[x / y % 10] == 0)
        z++;
        c[x / y % 10] = 1;
        x /= 10;
    }
    return z;
}
ll lg10(ll x)
{
    if (10000 <= x && x < 100000)
        re 5;
    if (x == 0)
        return 0;
    return lg10(x / 10) + 1;
}
ll g(ll x, ll mod)
{
    if (x == 0)
        re 0;
    return x / mod + g(x / mod, mod);
}
bool is_digit(char c)
{
    re ('0' <= c && c <= '9');
}

struct Matrix{
    ll a, b;
    vector<vector<ll>> x;
    Matrix(int a_, int b_)
    {
        a = a_;
        b = b_;
        x.resize(a);
        forn(i, a)
        {
            x[i].resize(b);
        }
    }
};

Matrix MatrixMultiplication(Matrix M, Matrix N)
{
    if (M.b != N.a)
    {
        exit(0);
    }
    ll k = M.b;
    Matrix K(M.a, N.b);
    for (int i = 0; i < M.a; i++)
    {
        for (int j = 0; j < N.b; j++)
        {
            for (int q = 0; q < k; q++)
            {
                K.x[i][j] += M.x[i][q] * N.x[q][j];
                K.x[i][j] %= MOD;
            }
        }
    }
    re K;
}

Matrix inqMatrix(Matrix A, ll q)
{
    if (q == 0)
    {
        if (A.a == A.b)
        {
            Matrix C(A.a, A.b);
            for (int i = 0; i < A.a; i++)
            {
                C.x[i][i] = 1;
            }
            re C;
        }
        else
        {
            exit(0);
        }
    }
    if (q == 1)
    {
        re A;
    }
    Matrix L = inqMatrix(A, q / 2);
    L = MatrixMultiplication(L, L);
    if (q % 2 != 0)
        L = MatrixMultiplication(L, A);
    re L;
}

struct Node
{
	int L, R;
	int result;
	int update;
	Node *ls, *rs;
	Node()
	{
		L = 0, R = 0, result = 0, update = 0;
		ls = nullptr;
		rs = nullptr;
	}
};

struct SegmentTree
{
	Node *root;
	int get(Node *nd)
	{
	    if (nd->ls == nullptr)
	    {
	        return -2999999999;
	    }
	    else
	    {
	        return max(nd->ls->result, nd->rs->result);
	    }
	}
	void Modify(Node *nd)
	{
		int L = nd->L;
		int R = nd->R;
		int M = (L + R) / 2;
		if (nd->ls == nullptr)
		{
			Node *left = new Node();
			(left)->L = L;
			(left)->R = M;
			nd->ls = left;
		}
		if (nd->rs == nullptr)
		{
			Node *right = new Node();
			(right)->L = M;
			(right)->R = R;
			nd->rs = right;
		}
		if (nd->update != 0)
		{
			nd->result = nd->update;
			nd->ls->update = nd->update;
			nd->ls->result = nd->ls->update;
			nd->rs->update = nd->update;
			nd->rs->result = nd->rs->update;
			nd->update = 0;
		}
		nd->result = get(nd);
	}
	void Update(int x, int l, int r, Node *nd)
	{
		int L = nd->L;
		int R = nd->R;
		if (l <= L && R <= r)
		{
			Modify(nd);
			nd->update = x;
			nd->result = x;
			return;
		}
		if (R <= l || r <= L)
		{
			return;
		}
		Modify(nd);
		Update(x, l, r, nd->ls);
		Update(x, l, r, nd->rs);
		nd->result = get(nd);
	}
	int ReqSegment(int l, int r, Node *nd)
	{
	    int L = nd->L;
	    int R = nd->R;
  	    if (l <= L && R <= r)
	    {
  	        Modify(nd);
  	        return nd->result;
  	    }
        if (R <= l || r <= L)
        {
      	    return -2999999999;
        }
        Modify(nd);
        return max(ReqSegment(l, r, nd->ls), ReqSegment(l, r, nd->rs));
    }
    SegmentTree (int n)
    {
        Node* X = new Node();
        X->L = 0;
        X->R = n;
        root = X;
    }
};

struct Tree_lca{
    vector<int> graph[200000];
    vector<int> line;
    int n;
    ll h[200000];
    ll color[200000];
    ll F[200000], L[200000];
    ll it;
    ll sparce[200000][30];
    ll H[200000];

    void dfs(int x, int heigth)
    {
        line.pb(x);
        h[x] = heigth;
        F[x] = min(F[x], it);
        L[x] = max(L[x], it);
        it++;
        color[x] = 1;
        for (int i = 0; i < graph[x].sz; i++)
        {
            if (color[graph[x][i]] == 0)
            {
                dfs(graph[x][i], heigth + 1);
                line.pb(x);
                F[x] = min(F[x], it);
                L[x] = max(L[x], it);
                it++;
            }
        }
    }
    int lca(int a, int b)
    {
        ll l = min(F[a], F[b]);
        ll r = max(L[a], L[b]);
        ll len = r - l + 1;
        ll j = H[len];
        ll x = sparce[l][j];
        ll y = sparce[r + 1 - (1 << j)][j];
        if (h[x] <= h[y])
        {
            re x;
        }
        else
        {
            re y;
        }
    }
    void build_lca_sparce()
    {
        dfs(0, 1);
        for (int i = 0; i < line.sz; i++)
        {
            sparce[i][0] = line[i];
            //cout << line[i] << " ";
        }
        for (int j = 1; j < 21; j++)
        {
            for (int i = 0; i + (1 << j) <= line.sz; i++)
            {
                ll x = sparce[i][j - 1];
                ll y = sparce[i + (1 << j) / 2][j - 1];
                if (h[x] <= h[y])
                {
                    sparce[i][j] = x;
                }
                else
                {
                    sparce[i][j] = y;
                }
            }
        }
    }
    Tree_lca()
    {
        it = 0;
        fill(F, F + 200000, INF);
        H[1] = 0;
        for (int i = 2; i < 200000; i++)
        {
            H[i] = H[i / 2] + 1;
        }
    }
};

#define bitcount __builtin_popcount
#define bitcountl __builtin_popcountll

#define RA(n, arr) cin >> n; forn(i, n) cin >> (arr)[i];
#define WA(n, arr) cout << n << "\n"; forn(i, n) cout << (arr)[i] << " ";
#define WWA(n, arr) forn(i, n) cout << (arr)[i] << " ";
#define RSA(n, arr) cin >> n; forn(i, n) cin >> (arr)[i]; sort(arr, arr + n);
#define WSA(n, arr) cout << n << "\n"; sort(arr, arr + n); forn(i, n) cout << (arr)[i] << " ";
#define WWSA(n, arr) sort(arr, arr + n); forn(i, n) cout << (arr)[i] << " ";
#define WSV(vec) cout << vec.size() << "\n"; sort(all(vec)); forn(i, vec.sz) cout << (vec)[i] << " ";
#define WWSV(vec) sort(all(vec)); forn(i, vec.sz) cout << (vec)[i] << " ";
//string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//vi cx, cy;
//______________________
ll w;

bool is366(int y)
{
    re (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

signed main()
{
    int y, z;
    cin >> y;
    z = is366(y);
    w = 0;
    y = y + 1;
    while (1)
    {
        w = w + 1 + is366(y);
        if (w % 7 == 0 && is366(y) == z)
        {
            cout << y;
            re 0;
        }
        y++;
    }
}