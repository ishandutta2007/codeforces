/*#include <bits/stdc++.h>
using namespace std;
bool ispal(string s) {
	for (int i = 0; i < s.size() / 2;i++)if (s[i] != s[s.size() - 1 - i])return 0;
	return 1;
}
int main() {
	string s;
	cin >> s;
	int n = s.size(),i,j;
	for (i = n; i >= 2; i--) {
		for (j = 0; j + i - 1 < n; j++) {
			if (!ispal(s.substr(j, i))) {
				printf("%d", i);
				return 0;
			}
		}
	}
	printf("0");
}*/
#include <bits/stdc++.h>
#define mmax(a,b) a=max(a,b);
using namespace std;
typedef long long ll;
map<ll, ll> m;
int main() {
	int n, nn, i;
	ll a, b;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld%lld", &a, &b);
		mmax(m[a], b);
	}
	scanf("%d", &nn);
	for (i = 0; i < nn; i++) {
		scanf("%lld%lld", &a, &b);
		mmax(m[a], b);
	}
	ll ans = 0;
	for (auto p : m)ans += p.second;
	printf("%lld", ans); getchar(); getchar();
}