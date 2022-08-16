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

const int N = 10005;
bitset<N> possible;
int l[N], r[N], x[N];
vector<int> add[N], sub[N];
vector<pair<int, pii>> queries;

const int BLOCK = 135;

int F[N], G[N];
int H[N];
int stmn[N];
set<int> changing;
bitset<N> ans;

bool check_here[2 * N];
int mx[N];
int main(){
	int n, q;
	sd(n); sd(q);
	memset(mx, -1, sizeof mx);
	for(int i = 1; i <= q; i++){
		sd(l[i]), sd(r[i]), sd(x[i]);
		queries.push_back({l[i], {1, x[i]}});
		queries.push_back({r[i] + 1, {-1, x[i]}});
	}

	sort(queries.begin(), queries.end());
	for(int i = 0; i < queries.size(); i++){
		mx[queries[i].F] = i;
	}

	for(int i = 1; i <= n+1; i++) if(mx[i] >= 0) check_here[mx[i]] = 1;
	int m = queries.size();

	for(int i = 1; (i-1) * BLOCK < m; i++){
		int st = (i - 1) * BLOCK;
		int en = min(m - 1, i * BLOCK - 1);
		memset(F, 0, sizeof F);
		for(int j = 0; j < st; j++){
			if(queries[j].S.F == 1){
				F[queries[j].S.S]++;
			}
			else F[queries[j].S.S]--;
		}
		bitset<N> bs;
		bs.set(0);
		changing.clear();
		memcpy(G, F, sizeof G);
		for(int j = st; j <= en; j++) changing.insert(queries[j].S.S), stmn[queries[j].S.S] = 1e9;
		memcpy(H, F, sizeof H);
		
		for(int j = st; j <= en; j++){
			H[queries[j].S.S] += queries[j].S.F;
			for(auto it : changing) stmn[it] = min(stmn[it], H[it]);
		}
		for(auto it : changing) G[it] = stmn[it];

		for(int j = 1; j <= n; j++){
			for(int l = 0; l < G[j]; l++) bs |= (bs << j);
		}

		bitset<N> store = bs;
		for(int j = st; j <= en; j++){
			if(queries[j].S.F == 1)
				F[queries[j].S.S]++;
			else F[queries[j].S.S]--;
			if(check_here[j]){
				bs = store;
				for(auto it : changing){
					for(int l = stmn[it] + 1; l <= F[it]; l++)
						bs |= (bs << it);
				}
				ans |= bs;
			}
		}
	}
	vector<int> valid;
	for(int i = 1; i <= n; i++) if(ans[i]) valid.push_back(i);
	printf("%d\n", (int)valid.size());
	for(auto it : valid) printf("%d ", it);
}