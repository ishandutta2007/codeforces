#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;
bool ipal(int n) {
	string s, t;
	s = t= to_string(n);
	reverse(all(t));
	return s==t;
}
const ll maxn = 1e7 + 33;
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	bitset<maxn> comp;
	vi primes;
	comp.set(0);
	comp.set(1);
	for(int i = 2; i < maxn; i++) {
		if(comp.test(i)) continue;
		primes.pb(i);
		for(ll j = i*1ll*i; j < maxn; j+=i)
			comp.set(j);
	}
	ll p, q;
	cin >> p >> q;
	int k = 0;
	ll pi = 0, pal = 0, ans = -1;
	for(int i = 1; i < maxn; i++) {
		pal += ipal(i);
		if(k < primes.size() && primes[k] == i) pi++, k++;
		if(q*pi <= p*pal)
			ans = i;
	}
	if(ans == -1)
		cout << "Palindromic tree is better than splay tree";
	else
		cout << ans;
}