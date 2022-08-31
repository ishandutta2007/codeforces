#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

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

vector<int> primes;
const int N = 5005;
const int P = 700;
int prime[N];
int freq[N];
int f[N][P];
int prefix[N];
ll prefix2[P][N];
ll total[N];
template<class T>
T get(T * pref, int l, int r, int MAX){
	return pref[l - 1] + pref[MAX - 1] - pref[r];
}

int main(){
	for(int i = 2; i < N; i++) if(!prime[i]){
		primes.push_back(i);
		for(int j = i; j < N; j+=i) prime[j] = 1;
	}
	for(int i = 1; i < N; i++){
		for(int j = 0; j < sz(primes); j++){
			int t = i;	
			int p = primes[j];
			while(t){
				f[i][j] += t / p;
				t /= p;
			}
		}
	}


	int n = 1000000;
	sd(n);
	for(int i = 1; i <= n; i++){
		int k = rand() % 5000 + 1; 
		sd(k);
		k = max(k, 1);
		for(int j = 0; j < P; j++)
			total[j] += f[k][j];
		
		freq[k]++;
	}

	for(int j = 1; j < sz(primes); j++){
		total[j] += total[j - 1];		
	}

	ll ans = 1LL<<60;
	// trace(ans);
	for(int i = 1; i < N; i++) prefix[i] = prefix[i - 1] + freq[i];
	for(int j = 0; j < sz(primes); j++) for(int i = 1; i < N; i++) prefix2[j][i] = prefix2[j][i - 1] + freq[i] * (ll) f[i][j];

	for(int i = 1; i < N; i++){
		int lo = 1, hi = N - 1;
		ll curr = 0;
		for(int j = sz(primes) - 1; j >= 0; j--){
			int cnt = get(prefix, lo, hi, N);
			ll sm = get(prefix2[j], lo, hi, N);
			curr += sm + cnt * (ll) f[i][j];
			while(lo < i && f[lo][j] != f[i][j]){
				curr += abs(f[i][j] - f[lo][j]) * (ll) freq[lo];
				lo++;
			}
			while(hi > i && f[hi][j] != f[i][j]){
				curr += abs(f[i][j] - f[hi][j]) * (ll) freq[hi];
				hi--;
			}
			ans = min(ans, curr + (j == 0 ? 0LL : total[j - 1]));
		}
	}
	printf("%lld\n", ans);
}