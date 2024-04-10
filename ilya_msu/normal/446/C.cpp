#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>



 
using namespace std; 
 
typedef long long ll; 
typedef long double ld;
typedef unsigned int uint; 
typedef unsigned long long ull; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 9;
const ll N = 300100;

vector<ll> fib;

ll getFib(ll f1, ll f2, ll len) {
	if (len == 1)
		return f1;
	if (len == 2)
		return f2;
	return (fib[len - 2] * f1 + fib[len - 1] * f2) % mod;
}

ll getSumFib(ll f1, ll f2, ll len) {
	return (getFib(f1, f2, len + 2) - f2 + mod) % mod;
}

struct segTree {
	int n;
	int sz;
	vector<ll> sum;
	vector<ll> add1, add2;
	ll build(int v, int l, int r, const vector<int>& a) {
		if (l == r) {
			sum[v] = a[l - 1];
			return sum[v];
		}
		sum[v] = build(2 * v, l, (l + r) / 2, a) + build(2 * v + 1, (l + r) / 2 + 1, r, a);
		if (sum[v] >= mod)
			sum[v] -= mod;
		return sum[v];
	}
	segTree(const vector<int>& a) {
		n = a.size();
		sz = 4 * n + 10;
		sum.assign(sz, 0);
		add1.assign(sz, 0);
		add2.assign(sz, 0);
		build(1, 1, n, a);
	}
	void add(int v, int tl, int tr, int l, int r, ll f1, ll f2) {
		if ((r < tl) || (l > tr))
			return;
		if ((tl == l) && (tr == r)) {
			add1[v] = (add1[v] + f1) % mod;
			add2[v] = (add2[v] + f2) % mod;
			sum[v] += getSumFib(f1, f2, r - l + 1);
			if (sum[v] >= mod)
				sum[v] -= mod;
			return;
		}
		int m = (tl + tr) / 2;
		add(2 * v, tl, m, l, min(r, m), f1, f2);
		int nl = max(m + 1, l);
		add(2 * v + 1, m + 1, tr, max(m + 1, l), r, getFib(f1, f2, nl - l + 1), getFib(f1, f2, nl - l + 2));
		sum[v] = (sum[2 * v] + sum[2 * v + 1] + getSumFib(add1[v], add2[v], tr - tl + 1)) % mod;
	}
	void add(int l, int r, ll f1, ll f2) {
		add(1, 1, n, l, r, f1, f2);
	}
	ll getSum(int v, int tl, int tr, int l, int r) {
		if ((r < tl) || (l > tr))
			return 0;
		if ((tl >= l) && (tr <= r))
			return sum[v];
		int m = (tl + tr) / 2;
		add(2 * v, tl, m, tl, m, add1[v], add2[v]);
		add(2 * v + 1, m + 1, tr, m + 1, tr, getFib(add1[v], add2[v], m + 2 - tl), getFib(add1[v], add2[v], m + 3 - tl));
		add1[v] = add2[v] = 0;
		return (getSum(2 * v, tl, m, l, r) + getSum(2 * v + 1, m + 1, tr, l, r)) % mod;


	}
	ll getSum(int l, int r) {
		return getSum(1, 1, n, l, r);
	}
};

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	fib.resize(N);
	fib[0] = 0, fib[1] = 1;
	for (int i = 2; i < N; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] >= mod)
			fib[i] -= mod;
	}
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	segTree tr(a);
	for (int i = 0; i < m; ++i) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1)
			tr.add(l, r, 1, 1);
		else
			cout << tr.getSum(l, r) << "\n";
		//cerr << i << endl;
	}
	
	return 0;
}