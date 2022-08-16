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

const ll MAXK = 1e15;
const int M = sqrt(MAXK * 1.05);

vector<int> primes;
bool not_prime[M];

void pre_prime(){
	for(int i = 2; i * i < M; i++)
		if(!not_prime[i])
			for(int j = i * i; j < M; j+= i)
				not_prime[j] = 1;
	for(int i = 2; i < M; i++) if(!not_prime[i]) primes.push_back(i);
}

vector<ll> factorize(ll n){
	vector<ll> ret;
	for(int i = 0; i < primes.size() && primes[i] * (ll) primes[i] <= n; i++){
		if(n % primes[i] == 0){
			while(n % primes[i] == 0){
				n /= primes[i];
			}
			ret.push_back(primes[i]);
		}
	}
	if(n != 1) ret.push_back(n);
	return ret;
}

map<pair<ll, ll>, string> ans;
map<ll, vector<ll>> to_find;
ll fn[10005], fk[10005];

const int N = 1e5 + 10;
const ll INF = 2e18;

vector<pair<int, ll>> con[N];
ll dist[N];

void dijkstra(int s, int n){
    priority_queue<pii,vector<pair<ll, int>>, greater<pair<ll, int>> > Q; 
    for(int i = 0; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    Q.push(pii(0,s));
    while(!Q.empty()) {
        pii top = Q.top();
        Q.pop();
        int v = top.second;
        ll d = top.first;
        if(d <= dist[v]) {
            for(auto it : con[v]){
                int v2 = it.first;
                ll cost = it.second;
                if(dist[v2] > dist[v] + cost) {
                    dist[v2] = dist[v] + cost;
                    Q.push(pair<ll, int>(dist[v2], v2));
                }
            }
        }
    }
}

string query(ll n, ll P){
	return n < dist[n % P] ? "NO" : "YES";
}

ll powr(ll a, ll b, ll c){
	ll ret = 1;
	for(; b; b >>= 1, a = (a * a) % c) if(b & 1) ret = (ret * a) % c;
	return ret;
}

ll inv (ll a, ll p){  return powr(a, p - 2, p);}

string query(ll n, ll p1, ll p2){
	if(n >= (p1 + 1) * (p2 + 1) - 1) return "YES";
	// a2 * p2 == n % p1
	ll a2 = ((n % p1) * inv(p2 % p1, p1)) % p1;
	return (n >= a2 * p2) ? "YES" : "NO";
}

int main(){
	pre_prime();
	int t;
	sd(t);
	for(int i = 1; i <= t; i++){
		ll n, k;
		scanf("%lld %lld", &n, &k);
		fn[i] = n; fk[i] = k;
		to_find[k].push_back(n);
	}

	for(auto it : to_find){
		ll k = it.F;
		vector<ll> prime_factors = factorize(k);
		if(prime_factors.empty()){
			for(auto it2 : it.S)
				ans[{k, it2}] = "NO";
		} else if(prime_factors.size() == 1){
			for(auto it2 : it.S)
				ans[{k, it2}] = (it2 % prime_factors[0] == 0 ? "YES" : "NO");
		} else if(prime_factors[0] < N){
			int P = prime_factors[0];
			for(int i = 0; i < N; i++) con[i].clear();
			for(int i = 0; i < P; i++)
				for(int j = 1; j < prime_factors.size(); j++)
					con[i].push_back({(i + prime_factors[j]) % P, prime_factors[j]});
			dijkstra(0, P - 1);
			for(auto it2 : it.S)
				ans[{k, it2}] = query(it2, P);
		} else{
			assert(prime_factors.size() == 2);
			ll p1 = prime_factors[0], p2 = prime_factors[1];
			for(auto it2 : it.S) ans[{k, it2}] = query(it2, p1, p2);
		}
	}

	for(int i = 1; i <= t; i++) printf("%s\n", ans[{fk[i], fn[i]}].c_str());
}