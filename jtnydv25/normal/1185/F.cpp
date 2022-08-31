#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())


#ifdef LOCAL
#define cerr cout
#else
#endif

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
const int N = 512;

int num_masks[N];
int num[N];
ll minCost[N];
ll secondMinCost[N];

int ind[N], ind2[N];
const ll INF = 1e18;
int main(){
	for(int i = 0; i < N; i++) minCost[i] = secondMinCost[i] = INF;
	int n, m;
	sd(n); sd(m);
	for(int i = 0; i < n; i++){
		int t, x; sd(t);
		int y = 0;
		for(int j = 0; j < t; j++){
			sd(x); x--;
			y |= 1 << x;
		}
		num_masks[y]++;
	}

	for(int i = 0; i < m; i++){
		int t, x, c; sd(c); sd(t);
		int y = 0;
		for(int j = 0; j < t; j++){
			sd(x); x--;
			y |= 1 << x;
		}
		if(c < minCost[y]){
			secondMinCost[y] = minCost[y];
			ind2[y] = ind[y];
			minCost[y] = c;
			ind[y] = i + 1;
		}
		else if(c < secondMinCost[y]) secondMinCost[y] = c, ind2[y] = i + 1;
	}

	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++) if((i & k) == k){
			num[i] += num_masks[k];
		}
	}

	int max_sat =0;
	ll min_cost = INF / 2;
	int i1, i2;
	for(int i = 0; i < N; i++){
		if(minCost[i] == INF) continue;
		if(num[i] > max_sat && secondMinCost[i] != INF){
			min_cost = minCost[i] + secondMinCost[i];
			max_sat = num[i];
			i1 = ind[i];
			i2 = ind2[i];
		} else if(num[i] == max_sat && minCost[i] + secondMinCost[i] < min_cost){
			min_cost = minCost[i] + secondMinCost[i];
			i1 = ind[i];
			i2 = ind2[i];
		}
		for(int j = 0; j < i; j++) if(minCost[j] != INF){
			int sat = num[i | j];
			ll cost = minCost[i] + minCost[j];
			if(sat > max_sat){
				max_sat = sat;
				min_cost = cost;
				i1 = ind[i]; i2 = ind[j];
			} else if(max_sat == sat && min_cost > cost){
				min_cost = cost;
				i1 = ind[i]; i2 = ind[j];
			}
		}
	}
	printf("%d %d\n", i1, i2);
}