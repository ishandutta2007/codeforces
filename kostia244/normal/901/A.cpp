#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 998244353;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int h, n, amb = 0;
	vi a;
	cin >> h;
	a.resize(h+1);
	for(auto &i : a) cin >> i, n += i;
	for(int i = 1; i <= h; i++)
		if(a[i] > 1&&a[i-1] > 1)
			amb=1;
	if(amb==0) {
		cout << "perfect";
		return 0;
	}
	cout << "ambiguous\n";
	int pr = 1;
	cout << "0 ";
	for(int i = 1; i <= h; i++) {
		for(int k = 0; k < a[i]; k++)
		cout << pr << " ";
		pr+=a[i-1];
	}
	cout << "\n";
	pr = 1;
		cout << "0 ";
		for(int i = 1; i <= h; i++) {
			for(int k = 0; k < a[i]; k++)
			cout << (pr+(a[i-1]>1&&k==0)) << " ";
			pr+=a[i-1];
		}
		cout << "\n";
}