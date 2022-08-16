#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, iknt>
#define F first
#define S second

const int N = 1e5 + 10;
const int D = N * 10;
int d[N], f[N], t[N], c[N], perm[N];
vector<int> flights[D];
multiset<int> arr[N], dep[N];
ll ARR[N], DEP[N];
const ll INF = 1e12;

ll get(multiset<int> & ms){
	return ((ms.empty()) ? INF : (*ms.begin()));
}

int main(){
	int m, n, k;
	sd(n); sd(m); sd(k);
	for(int i = 1; i <= m; i++){
		sd(d[i]);
		sd(f[i]);
		sd(t[i]);
		sd(c[i]);
		flights[d[i]].pb(i);
	}
	for(int i = 1; i <= n; i++) ARR[i] = DEP[i] = INF;

	ll cost = INF;
	ll cost2 = 0;
	for(int i = k + 1; i < D; i++){
		for(int ind : flights[i]){
			if(f[ind] == 0){
				dep[t[ind]].insert(c[ind]);
				DEP[t[ind]] = *dep[t[ind]].begin();
			}
		}
	}
	for(int i = 1; i <= n; i++) cost2 += DEP[i] + ARR[i];
	for(int i = 1; i < D - k - 1; i++){
		cost = min(cost, cost2);
		for(int ind : flights[i]){
			if(t[ind] == 0){
				arr[f[ind]].insert(c[ind]);
				cost2 -= ARR[f[ind]];
				ARR[f[ind]] = *arr[f[ind]].begin();
				cost2 += ARR[f[ind]];
			}
		}
		for(int ind : flights[i + k]){
			if(f[ind] == 0){
				dep[t[ind]].erase(dep[t[ind]].find(c[ind]));
				cost2 -= DEP[t[ind]];
				DEP[t[ind]] = get(dep[t[ind]]);
				cost2 += DEP[t[ind]];
			}
		}
		
	}
	cost = min(cost, cost2);
	if(cost >= INF) cost = -1;
	printf("%lld", cost);
}