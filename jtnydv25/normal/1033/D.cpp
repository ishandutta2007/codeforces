#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int N = 505;
ll to_factorize[N], a[N];
map<ll, int> freq;
ll t;

ll is_prime_square(ll x){
	t = max(0., sqrt(x) - 100);
	while(t * t < x) t++;
	return t * t == x ? t : 0;
}

ll is_prime_cube(ll x){
	t = max(0., cbrt(x) - 100);
	while(t * t * t < x) t++;
	return t * t * t == x ? t : 0;
}

ll is_prime_sqsq(ll x){
	t = max(0., sqrt(sqrt(x)) - 100);
	while(t * t * t * t < x) t++;
	return t * t * t * t == x ? t : 0;
}

set<ll> known_primes;
map<ll, int> freq_primes;
set<ll> remaining;
set<ll> new_primes;

const int mod = 998244353;
int main(){
	int n; 
	sd(n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		freq[a[i]]++;
	}
	int cnt = 0;
	for(auto it : freq){
		to_factorize[++cnt] = it.F;
		remaining.insert(it.F);
	}

	for(int i = 1; i <= cnt; i++){
		if(is_prime_sqsq(to_factorize[i])){
			freq_primes[t] += 4 * freq[to_factorize[i]];
			remaining.erase(to_factorize[i]);
			new_primes.insert(t);
		} else if(is_prime_cube(to_factorize[i])){
			freq_primes[t] += 3 * freq[to_factorize[i]];;
			remaining.erase(to_factorize[i]);
			new_primes.insert(t);
		} else if(is_prime_square(to_factorize[i])){
			freq_primes[t] += 2 * freq[to_factorize[i]];;
			remaining.erase(to_factorize[i]);
			new_primes.insert(t);
		}
	}

	for(ll it1 : remaining)
			for(ll it2 : remaining){
				if(it1 != it2){
					ll g = __gcd(it1, it2);
					if(g != it1 && g != it2 && g != 1){
						new_primes.insert(g);
						new_primes.insert(it1 / g);
						new_primes.insert(it2 / g);
					}
				}	
			}

	known_primes = new_primes;
	while(!new_primes.empty()){
		set<ll> deletions;
		set<ll> additions;
		for(auto p : new_primes)
			for(auto it : remaining){
				if(deletions.count(it)) continue;
				if(it % p == 0){
					freq_primes[p] += freq[it];
					freq_primes[it / p] += freq[it];
					deletions.insert(it);
					if(!known_primes.count(p)){
						additions.insert(p);
					}
					if(!known_primes.count(it / p)){
						additions.insert(it / p);
					}
				}
			}
		for(auto it : deletions) remaining.erase(it);
		for(auto it : additions) known_primes.insert(it);
		new_primes =additions;
	}
	int ans = 1;
	for(auto it : freq_primes) ans = (ans * (ll) (it.S + 1)) % mod;
	for(auto it : remaining){
		ans = (ans * (ll) (freq[it] + 1) * (ll) (freq[it] + 1)) % mod;
	}
	printf("%d\n", ans);
}