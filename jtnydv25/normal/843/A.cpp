#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
const int N = 1e5 + 10;
int perm[N], iperm[N], A[N];
set<int> s; map<int, int> pos;
vector<int> con[N];
int comp = 0;
int vis[N];
vector< vector<int> > vec;
vector<int> v;
void dfs(int s){
	vis[s] = 1;
	v.pb(s);
	for(int v : con[s]) if(!vis[v]) dfs(v);
}

int main(){
    int t = 1, n;
    // sd(t);
    while(t--){
        sd(n);
        for(int i = 1; i <= n; i++){
        	sd(A[i]);
        	s.insert(A[i]);
        	pos[A[i]] = i;
        }
        int it = 0;
        for(int x : s){
        	perm[pos[x]] = ++it;
        	con[pos[x]].push_back(it);
        }
        for(int i = 1; i <= n; i++){
        	if(!vis[i]){
        		v.clear();
        		comp++; dfs(i);
        		vec.pb(v);
        	}
        }
        printf("%d\n", comp);
        for(auto it : vec){
        	printf("%d ", (int)it.size());
        	for(int x : it) printf("%d ", x);
        	printf("\n");
        }
    }
}