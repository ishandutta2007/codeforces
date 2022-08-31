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

ll n;
ll s;

ll getCount(int c){
	vector<int> old = {1};
	ll sm = 1;
	int d = 2;
	int curr = 2;
	for(; curr <= n; d++){
		vector<int> now;
		for(auto it : old){
			for(int iter = 0; iter < c && curr <= n; iter++, curr++){
				now.push_back(curr);
				sm += d;
			}
		}
		old = now;
	}
	return sm;
}

int par[N];
int child[N];
int depth[N];
set<pair<int, int> > st;

void build(int c){
	for(int i = 1; i <= n; i++){
		depth[i] = i, par[i] = i - 1;
		if(i != n) child[i] = 1;
		st.insert({depth[i], i});
	}
	ll curr = (n * (n + 1)) >> 1;
	int node = n;
	int done = 0;
	while(curr > s){
		while(!st.empty()){
			auto it = *st.begin();
			if(child[it.S] >= c){
				st.erase(it);
				continue;
			}
			if(curr - depth[node] + it.F + 1 >= s){
				st.erase({depth[node], node});
				curr -= depth[node];
				curr += it.F + 1;
				child[node - 1]--;
				par[node] = it.S;
				child[it.S]++;
				if(child[it.S] >= c){
					st.erase(it);
				}
				depth[node] = it.F + 1;
				st.insert({depth[node], node}); 
				break;
			} else{
				st.erase(it);
			}
		}
		node--;
	}
}

int main(){
	scanf("%lld %lld", &n, &s);
	if(2 * s > n * (n + 1) || s < 2 * n - 1){
		printf("No\n");
		return 0;
	}

	if(s == ((n * (n + 1)) >> 1)){
		printf("Yes\n");
		for(int i = 2; i <= n; i++) printf("%d ", i - 1);
			printf("\n");
		return 0;
	}

	int lo = 1, hi = n - 1;
	while(lo < hi){
		int mid = (lo + hi) >> 1;
		if(getCount(mid) <= s){
			hi = mid;
		} else{
			lo = mid + 1;
		}
	}

	build(lo);
	printf("Yes\n");	
	for(int i = 2; i <= n; i++) printf("%d ", par[i]);
		printf("\n");

}