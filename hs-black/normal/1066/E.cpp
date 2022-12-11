#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 200005;
const int P = 998244353;
int a[N];
long long mi[N];
char s[N];
char sb[N];
int main() {
	int n, m;
	cin >> n >> m;
	mi[0] = 1;
	for (int i = 1;i <= n; i++) {
		mi[i] = mi[i-1] << 1;
		if (mi[i] >= P) mi[i] -= P;
	}
	scanf ("%s", s + 1);
	scanf ("%s", sb + 1);
	for (int i = m;i >= 1; i--)
		if (sb[i] == '1') a[i] = a[i+1] + 1;
		else a[i] = a[i+1];
	ll ans = 0;
	char *p = s; 
	if (n > m) {
		p += n - m;
		n = m;
	}
	for (int i = n;i >= 1; i--) {
		if (p[i] == '1')
		ans += (a[1] - a[m - n + i + 1]) * mi[n - i];
		ans %= P;
	}
	cout << ans << endl;
	return 0;
}
/*
10 1
1111111111
1

*/