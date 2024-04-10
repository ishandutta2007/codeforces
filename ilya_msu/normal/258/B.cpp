#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
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
 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-8;
const ll INF = 777777777777 + 1;
vector<int> a(10, 0);

int pow(int x, int st) {
	/*if (st == 0)
		return 0;*/
	int res = 1;
	for (int i = 0; i < st; ++i)
		res *= x;
	return res;
}

ll c(int n, int k) {
	ll res = 1;
	for (int i = 0; i < k; ++i) {
		res *= n - i;
		res /= i + 1;
	}
	return res;
}

void add(ll m, int shift) {
	if (m < 1)
		return;
	if (m == 1) {
		++a[shift];
		return;
	}
	if (m <= 10) {
		for (int i = 0; i < m; ++i) {
			if ((i == 4) || (i == 7))
				++a[shift + 1];
			else
				++a[shift];
		}
		return;
	}
	/*if (m == 0) {
		++a[shift];
		return;
	}
	if (m == 1) {
		++a[shift];
		return;
	}*/
	ll d = 1;
	int s = 0;
	while (d * 10 <= m) {
		d *= 10;
		++s;
		

	}
	if (m == d) {
		a[shift] += pow(8, s);
		for (int i = 1; i <= s; ++i) {
			a[shift + i] += c(s, i) * pow(2, i) * pow(8, s - i);
		}
		return;
	}
	int x = m / d;

	for (int i = 0; i < x; ++i) {
		if ((i == 4) || (i == 7))
			add(d, shift + 1);
		else
			add(d, shift);
	}
	if ((x == 4) || (x == 7))
		++shift;
	add(m - d * x, shift);
}
const ll inv[] = {0, 1, 500000004, 166666668, 41666667, 808333339, 301388891};

ll mod = 1000 * 1000 * 1000 + 7;
ll cm(ll n, int k) {
	ll res = 1;
	for (int i = 0; i < k; ++i) {
		res = (res * (n - i)) % mod;
	}
	res = (res * inv[k]) % mod;
	return res;
}

ll get(int s, int k) {
	if (k == 0)
		return 1;
	ll res = 0;
	for (int i = 0; i < s; ++i) {
		--a[i];
		if (a[i] >= 0)
			res = (res + (ll)(a[i] + 1) * get(s - i, k - 1)) % mod;
		++a[i];
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll m;
	cin >> m;
	add(m + 1, 0);
	--a[0];
	/*for (int i = 0; i < 10; ++i)
		cout << a[i] << " ";
	cout << endl;
	return 0;*/
	ll res = 0;
	for (int s = 1; s <= 9; ++s) {
		ll cur = ((ll)(a[s]) * get(s, 6)) % mod;
		res = (res + cur) % mod;
	}
	
	cout << res << endl;


	return 0;
}