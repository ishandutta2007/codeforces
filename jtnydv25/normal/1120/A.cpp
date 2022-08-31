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

const int N = 500005;
int a[N], b[N], g[N], h[N], curr[N];

int cnt;
int main(){
	int n, k, m, s;
	sd(m); sd(k); sd(n); sd(s);
	vector<int> removals;
	for(int i = 1; i <= m; i++) sd(a[i]);
	for(int i = 1; i <= s; i++){
		sd(b[i]);
		g[b[i]]++;
	}

	int total = 0;

	for(int i = 1; i < N; i++) if(g[i]){	
		h[i] = g[i];
		total++;
	}

	int i = 1, j = 0, rem = total;

	for(; i <= m; i++){
		while(rem && j < m){
			j++;
			int t = a[j];			
			if(g[t]) curr[t]++;
			if(g[t] && h[t] > 0){
				h[t]--;
				if(!h[t]) rem--;
			}
		}
		if(!rem){
			int temp_j = j;
			j = max(j, i + k - 1);
			if(j > m) break;
			int lft = (i - 1) / k;
			int rgt = (m - j) / k;
			if(lft + rgt + 1 >= n){
				int  num_lft = max(0, n - 1 - rgt);
				int num_rgt = n - 1 - num_lft;

				for(int x = 1; x <= (i - 1) % k; x++) removals.push_back(x);
				rem = total;
				int to_remove = j - i + 1 - k;

				for(int x = i; x <= j; x++){
					int t = a[x];
					if(g[t] > 0){
						g[t]--;
						if(!g[t]) rem--;
					} else if(to_remove){removals.push_back(x), to_remove--;}
				}
				printf("%d\n", (int) removals.size());
				for(auto it : removals) printf("%d ", it);
				return 0;
			}
			j = temp_j;
		} else{
			break;
		}		
		if(g[a[i]] > 0){
			int t = a[i];
			curr[t]--;
			if(curr[t] < g[t]){
				h[t]++;
				rem++;
			}
		}
	}
	printf("-1\n");
}