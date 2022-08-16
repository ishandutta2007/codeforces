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

const int INF = 1e9;
set<int> st;
char s[20];
const int mod = 1e9 + 7;
int main(){
	int best_bid = -INF, best_ask = INF;
	int t = 0;
	int n; sd(n);
	int ans = 1;
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		int p; sd(p);
		if(s[1] == 'D'){
			// ADD p
			if(p > best_bid && p < best_ask){
				t++;
			}
			st.insert(p);
		} else{
			// ACCEPT p
			if(!st.count(p)){
				printf("0\n");
				return 0;
			}
			if(p > best_bid && p < best_ask){
				ans += ans;
				if(ans >= mod) ans -= mod;
			} else{
				if(p != best_bid && p != best_ask){
					printf("0\n");
					return 0;
				}
			}
			auto it = st.find(p);
			best_bid = (it == st.begin()) ? -INF : *(--it);
			it = st.upper_bound(p);
			best_ask = (it == st.end()) ? INF : *it;
			st.erase(p);
			t = 0;
			// trace(i, best_bid, best_ask, p);
		}		
	}
	
	ans = (ans * (ll) (t + 1)) % mod;
	printf("%d\n", ans);
}