#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e6 + 55;
bitset<maxn> p;
int a, b, k;
bool can(int l) {
	int c = 0;
	for(int i = a; i <= b; i++) {
		c += !p[i];
		if(i-l>=a) c -= !p[i-l];
		if(i-l+1>=a&&c<k) return false;
	}
	return c>=k;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	p.set(0);
	p.set(1);
	for(int i = 2; i < maxn; i++) {
		if(p.test(i)) continue;
		for(ll j = i*1ll*i; j < maxn; j+=i) {
			p.set(j);
		}
	}
	cin >> a >> b >> k;
	if(!can(b-a+1)) return cout << -1, 0;
	int ans = 0;
	for(int i = 1<<19; i; i>>=1)
		if(!can(ans+i)) ans += i;
	cout << ans+1;
}