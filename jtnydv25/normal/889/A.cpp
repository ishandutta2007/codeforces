#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

const int N = 2e5 + 10;
int t[N], lst[N], vis[N];
vector<int> con[N];
int comp = 0;
void dfs(int s){
	vis[s] = 1;
	for(int v : con[s])
		if(!vis[v]) dfs(v);
}
int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++) sd(t[i]);
	for(int i = n; i >= 1; i--){
		if(lst[i]){
			con[i].push_back(lst[i]);
		}
		lst[t[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			comp++;
			dfs(i);
		}
	}
	printf("%d\n", comp);
}