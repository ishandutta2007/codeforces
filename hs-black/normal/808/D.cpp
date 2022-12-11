#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#define ll long long
using namespace std;
const int N = 100050;
multiset<ll> s1, s2;
int a[N];
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
int main() {
	int n = read();
	for (int i = 1;i <= n; i++) a[i] = read();
	ll sum1 = 0, sum2 = 0;
	for (int i = 1;i <= n; i++) {
		sum1 += a[i];
		s1.insert(a[i]);
	}
	set<ll>::iterator it;
	for (int i = n;i >= 1; i--) {
		sum2 += a[i];
		s2.insert(a[i]);
		sum1 -= a[i];
		it = s1.find(a[i]);
		s1.erase(it);
		if (sum1 == sum2) {
			cout << "YES\n";
			return 0;
		}
		if (sum1 > sum2) {
			if ((sum1 - sum2) & 1) continue;
			if (s1.find((sum1-sum2)/2) != s1.end()) {
				cout << "YES\n";
				return 0;
			}
		}
		else {
			if ((sum2 - sum1) & 1) continue;
			if (s2.find((sum2-sum1)/2) != s2.end()) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}