#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
int main() {
	ll sum = 0, n, maxn = 0;
	cin >> n;
	for (int i = 1;i <= n; i++) {
		ll x;
		cin >> x;
		maxn = max(maxn, x);
		sum += x;
	}
	if (sum & 1) {
		cout << "NO\n";
		return 0;
	}
	if (maxn * 2 > sum) {
		cout << "No\n";
		return 0;
	}
	cout << "YES\n";
	return 0;
}