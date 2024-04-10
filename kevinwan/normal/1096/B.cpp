#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int mn = 0;
int main() {
	int n,a,b,i;
	string s;
	scanf("%d", &n);
	cin >> s;
	for (i = 0; i < n; i++) {
		if (s[i] == s[0])a = i + 1;
		else break;
	}
	for (i = n - 1; i >= 0; i--) {
		if (s[i] == s[n - 1])b = n - i;
		else break;
	}
	if (s[n - 1] == s[0])printf("%lld", 1LL * (a + 1)*(b + 1) % mod);
	else printf("%d", 1 + a + b);
}