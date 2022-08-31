#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 2005;
int val[N], perm[N];
vector<int> con[N];
int F[N];
bool cmp(int i, int j){
	return val[i] > val[j];
}
int main(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> val[i];
		perm[i] = i;	
	}
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		con[u].push_back(v);
		con[v].push_back(u);
		F[u] += val[v];
		F[v] += val[u];
	}
	sort(perm + 1, perm + n + 1, cmp);
	int ans = 0;
	for(int j = 1; j <= n; j++){
		int i = perm[j];
		ans += F[i];
		for(int v : con[i]) F[v] -= val[i];
	}
	cout << ans;
}