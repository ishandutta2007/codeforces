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
int target[N];

set<int> now[N];

int perm[N];

set<pair<int, int> > st;

vector<pair<int, pair<int, int> > > transfers;

int main(){
	int n, m, t = 0; sd(n); sd(m);
	for(int i = 1; i <= n; i++){
		int sz; sd(sz);
		perm[i] = i;
		for(int j = 1; j <= sz; j++){
			int z; sd(z);
			now[i].insert(z);
		}
		t += sz;
		st.insert({sz, i});
	}

	int diff = 0;
	int x = t / n, y = t % n;

	for(int i = y + 1; i <= n; i++){
		target[perm[i]] = x;
	}

	// int mindiff = (y != 0);

	while(1){
		auto it1 = *st.begin(), it2 = *st.rbegin();
		int i = it1.S, j = it2.S;
		int curr_i = it1.F, curr_j = it2.F;

		int max_transfer = (curr_j - curr_i) >> 1;
		max_transfer = min(max_transfer, max(1, curr_j - x - 1));
		max_transfer = min(max_transfer, max(1, x - curr_i));                                      

		if(max_transfer == 0) break;

		int done = 0;
		vector<int> removed;
		for(auto it : now[j]){
			if(done >= max_transfer) break;
			if(!now[i].count(it)){
				removed.push_back(it);
				transfers.push_back({j, {i, it}});
				++done;
			}
		}
		for(auto it : removed){
			now[i].insert(it);
			now[j].erase(it);
		}
		st.erase(it1); st.erase(it2);
		st.insert({now[i].size(), i});
		st.insert({now[j].size(), j});
	}

	printf("%d\n", (int)transfers.size());
	for(auto it : transfers) printf("%d %d %d\n", it.F, it.S.F, it.S.S);
}