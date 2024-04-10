#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int mn = 5e6 + 10;
int n;
ull h[mn], r[mn],p[mn];
ull m;
ull get(int a, int b) {
	if (a == 0)return h[b];
	return h[b] - h[a - 1] * p[b - a + 1];
}
ull rget(int a, int b) {
	if (b == n - 1)return r[a];
	return r[a] - r[b + 1] * p[b + 1 - a];
}
bool ispal(int a, int b) {
	return get(a, b) == rget(a, b);
}
int k[mn];
int main() {
	string s;
	srand(time(0));
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	m = rand()*2+ 236471;
	h[0] = s[0];
	n = s.size();
	int i;
	for (i = 1; i < n; i++)h[i] = h[i - 1] * m + s[i];
	r[n - 1] = s[n - 1];
	for (i = n - 2; i >= 0; i--)r[i] = r[i + 1] * m + s[i];
	p[0] = 1;
	for (i = 1; i <= n; i++)p[i] = p[i - 1] * m;
	ll ans = 1;
	k[0] = 1;
	for (i = 1; i < n; i++)if (ispal(0, i))k[i] = k[(i - 1) / 2] + 1,ans+=k[i];
	printf("%lld", ans);
}