#include<bits/stdc++.h>
using namespace std;
#define DFS while(!q.empty()){q.pop();}memset(dp1,0,n*4+1);res=0;memset(used,0,n+1);q.push(a);used[a]=1;while(!q.empty()){k=q.front();q.pop();for(i=0;i<v[k].size();i++){if(!used[v[k][i]]){used[v[k][i]]=1;dp1[v[k][i]]=dp1[k]+1;q.push(v[k][i]);}}}
int i,j,n,a,b,da,db,t,dp1[100500],x,y,res,k,tmp;
bool used[100500]; 
vector<int> v[100500];
queue<int> q;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		
		
		for(i=1;i<=n-1;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(da*2>=db){puts("Alice");continue;}
		DFS;
		if(dp1[b]<=da){
			puts("Alice");continue;
		}
		
		for(i=1;i<=n;i++){
			if(dp1[i]>res){res=dp1[i];a=i;}
		}
		
		DFS;
				
		for(i=1;i<=n;i++){
			if(dp1[i]>res){res=dp1[i];}
		}

		if(res<=da*2){
			puts("Alice");
		}else{
			puts("Bob");
		}
	}
}