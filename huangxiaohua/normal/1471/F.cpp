#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma optimize(3)
int i,j,k,n,m,t,x,y,used[300500],tmp;
vector<int> v[300500],res;
queue<int> q;

void dfs(int k){
    int i;
	if(used[k]){return;}
	tmp++;used[k]=1;
	for(i=0;i<v[k].size();i++){
		if(!used[v[k][i]]){dfs(v[k][i]);}
	}
}

int main(){
	scanf("%d",&t);
	
	while(t--){
		scanf("%d%d",&n,&m);
		res.clear();
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		memset(used,0,n*4+50);
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		tmp=0;
		dfs(1);
		if(tmp!=n){puts("NO");continue;}
		memset(used,0,n*4+50);
		
		q.push(1);
		while(!q.empty()){
			
			k=q.front();q.pop();
			if(used[k]==2){continue;}
			if(!used[k]){
				res.push_back(k);
				for(i=0;i<v[k].size();i++){
					if(used[v[k][i]]!=2){
						used[v[k][i]]=1;
						q.push(v[k][i]);
					}
				}
			}
			else{
				for(i=0;i<v[k].size();i++){
					if(used[v[k][i]]!=2){
						q.push(v[k][i]);
					}
				}
			}
			used[k]=2;
		}
		
		printf("YES\n%d\n",res.size());
		for(i=0;i<res.size();i++){
			printf("%d ",res[i]);
		}puts("");
	}
}