//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, x, l1, r1, n, p, a[maxn], c[maxn];
long long ans;
set<pll> s;
set<ll> d;

long long pw(long long pa, long long pb){
	if(pb == 0) return 1;
	long long pc = pw(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb & 1) pc = (pc * pa) % mod;
	return pc;
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> p;
		for(ll i = 0; i < n; i++){
			cin >> c[i];
		}
		if(p == 1){
			cout << n % 2 << '\n';
			continue;
		}
		sort(c, c + n, greater<ll>());
		s.clear();
		s.insert(Mp(inf, inf));
		s.insert(Mp(-1ll, -1ll));
		d.clear();
		d.insert(inf);
		for(ll i = 0; i < n; i++){
			set<pll>::iterator it = s.upper_bound(Mp(c[i], -1ll));
			it--;
			if(it -> S > c[i]){
				l1 = it -> F;
				r1 = it -> S;
				s.erase(it);
				if(l1 < c[i]) s.insert(Mp(l1, c[i]));
				if(c[i] + 1 < r1) s.insert(Mp(c[i] + 1, r1));
				a[c[i]] = p - 2;
				if(p - 2) d.insert(c[i]);
				continue;
			}
			l1 = *d.lower_bound(c[i]);
			it = s.lower_bound(Mp(c[i], -1ll));
			r1 = it -> F;
			if(l1 > maxn && r1 > maxn){
				a[c[i]]++;
				d.insert(c[i]);
			}
			else if(l1 < r1){
				a[l1]--;
				if(a[l1] == 0) d.erase(l1);
				if(l1 > c[i]) s.insert(Mp(c[i], l1));
			}
			else{
				l1 = it -> S;
				s.erase(it);
				a[r1] = p - 2;
				if(a[r1]) d.insert(r1);
				if(r1 > c[i]) s.insert(Mp(c[i], r1));
				if(r1 + 1 < l1) s.insert(Mp(r1 + 1, l1));
			}
		}
		ans = 0;
		for(set<pll>::iterator it = s.begin(); it != s.end(); it++){
			if(it -> F < it -> S) ans = (ans + pw(p, it -> S) - pw(p, it -> F)) % mod;
		}
		for(set<ll>::iterator it = d.begin(); it != d.end(); it++){
			if(*it < maxn) ans = (ans + pw(p, *it) * a[*it]) % mod, a[*it] = 0;
		}
		cout << (ans + mod) % mod << '\n';
	}
	
	return 0;
}