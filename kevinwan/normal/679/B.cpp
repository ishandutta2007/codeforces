#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, pair<ll, int>> m;
ll rt(ll x) {
	ll cur = 0;
	for (ll i = 1 << 19; i; i >>= 1)if ((cur + i)*(cur + i)*(cur + i) <= x)cur += i;
	return cur;
}
void solve(ll x) {
	if (x < 8) { m[x] = { x,x }; return; }
	if (m.find(x) != m.end())return;
	ll big = rt(x),a=big * big*big,b=(big-1)*(big-1)*(big-1);
	solve(x-a);
	solve(a-b-1);
	pair<ll, int> aa = m[x - a], bb = m[a-b-1];
	if (bb.second > aa.second)m[x] = { bb.first + b,bb.second + 1 };
	else m[x] = { aa.first + a,aa.second + 1 };
}
int main() {
	ll n;
	scanf("%lld", &n);
	solve(n);
	printf("%d %lld", m[n].second, m[n].first);
	getchar(); getchar();
}