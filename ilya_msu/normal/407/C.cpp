#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<long double, long double> pdd;

typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 10000000;
const int N = 100 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;

vector<ll> factor(N), invFactor(N);


void sum(vector<ll>& a) {
	for (int i = 1; i < a.size(); ++i)
		a[i] = (a[i] + a[i - 1] + MOD) % MOD;
}

void dif(vector<ll>& a) {
	for (int i = a.size() - 1; i > 0; --i)
		a[i] = (a[i] - a[i - 1] + MOD + MOD) % MOD;
}

ll power(ll a, int n) {
	ll res = 1;
	while(n) {
		if (n & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		n /= 2;
	}
	return res;
}

ll c(ll n, ll k) {
	ll res = (((factor[n] * invFactor[k]) % MOD) * invFactor[n - k]) % MOD;
	return res;
}

void init() {
	factor[0] = 1;
	for (int i = 1; i < N; ++i)
		factor[i] = (factor[i - 1] * i) % MOD;
	for (int i = 0; i < N; ++i)
		invFactor[i] = power(factor[i], MOD - 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	init();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<vector<pii> > mod(101);
	int l, r, k;
	for (int i = 0; i < m; ++i) {
		cin >> l >> r >> k;
		mod[k].push_back(pii(l - 1, r - 1));
		/*if (r + 1 < n)
			a[r + 1] = (a[r + 1] - c(r - l + k + 1, k) + MOD) % MOD;*/
	}
	for (int i = 0; i <= 100; ++i) {
		dif(a);
		for (int j = i; j < 101; ++j) {
			for (int ind = 0; ind < mod[j].size(); ++ind) {
				int l = mod[j][ind].first, r = mod[j][ind].second;
				if (r + 1 < n)
					a[r + 1] = (a[r + 1] + MOD - c(r - l + j - i, j - i)) % MOD;
			}
		}
	}
	for (int i = 100; i >= 0; --i) {
		for (int j = 0; j < mod[i].size(); ++j) {
			int l = mod[i][j].first;
			int r = mod[i][j].second;
			++a[l];
		}
		sum(a);
	}
	for (int i = 0; i < n; ++i)
		cout << a[i] % MOD << " ";
	cout << endl;

    return 0;
}