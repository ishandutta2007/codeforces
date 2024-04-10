#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MOD 1000000007

vector<vector<int>> g;
vector<char> cl,mk;
vector<int> c1,c2;

int dfs(int v){
	int sum=0;
	mk[v] = 1;
	if(cl[v]==0){
		if(!g[v].empty()){
			cl[v] = 1;
			if(cl[v]==1){
				c1.push_back(v);
			}else{
				c2.push_back(v);
			}
		}else{
			cl[v] = 66;
		}
	}
	for(auto u: g[v]){
		if(cl[u]==cl[v]){
			return -1;
		}
		if(!mk[u]){
			cl[u] = 3-cl[v];
			if(cl[u]==1){
				c1.push_back(u);
			}else{
				c2.push_back(u);
			}
			sum += dfs(u);
		}
	}
	if(sum<0){
		return -1;
	}
	return 0;
}

int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	g.resize(n,vector<int>());
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cl.resize(n,0);
	mk.resize(n,0);
	c1.clear();
	c2.clear();
	int sm = 0;
	while(1){
		auto it = find(cl.begin(),cl.end(),0);
		if(it==cl.end()){
			break;
		}
		sm += dfs(it-cl.begin());
		if(sm<0){
			printf("-1");
			return 0;
		}
	}
	printf("%d\n",c1.size());
	for(int i=0;i<c1.size();i++){
		if(i>0){
		   printf(" ");
		}
		printf("%d",c1[i]+1);
	}
	printf("\n%d\n",c2.size());
	for(int i=0;i<c2.size();i++){
		if(i>0){
		   printf(" ");
		}
		printf("%d",c2[i]+1);
	}
}