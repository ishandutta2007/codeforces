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

const int N = 100005;
ll b[N];

vector<ll> vec[65];
vector<ll> curr;

const int inf = 1e9;
int clz(unsigned long long N) {
    return N ? 63 - __builtin_clzll(N) : -inf;
}

bool ok = 1;
void get(int i){
	if(!ok) return;
	vector<ll> nw;
	int curr_parity = 0;
	int ind = 0;
	for(ll add : vec[i]){
		// trace("adding", add);
		while(curr_parity && ind < curr.size()){
				nw.push_back(curr[ind]);
				if(curr[ind] >> i & 1) curr_parity = 0;
				ind++;
		}
		if(curr_parity){
			ok = 0;
			// cerr << add << " " << i << endl;
			return;
		} else{
			curr_parity = 1;
			nw.push_back(add);
		}
	}
	while(ind < curr.size()) nw.push_back(curr[ind]), ind++;
	curr = nw;
	// if(i <= 5){for(auto it : curr) cerr << it << " "; cerr << endl;}
}

int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", b + i);
		int msb = clz(b[i]);
		vec[msb].push_back(b[i]);
	}
	for(int i = 60; i >= 0; i--) get(i);
	if(!ok){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(auto it : curr) printf("%lld ", it);
}