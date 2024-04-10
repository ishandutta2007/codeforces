#include<bits/stdc++.h>
using namespace std;
 
int i,j,n,a,b,da,db,t,dp1[100500],dp2[100500],x,y,res,used[100500],k,tmp;
vector<int> v[100500];
queue<int> q;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		res=0;
		while(!q.empty()){
			q.pop();
		}
		memset(dp1,0,n*4+10);
		memset(used,0,n*4+10);
		for(i=1;i<=n-1;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(da*2>=db){puts("Alice");continue;}
		
		q.push(a);used[a]=1;
		while(!q.empty()){
			k=q.front();q.pop();
			//printf("%d\n",k);
			for(i=0;i<v[k].size();i++){
				if(!used[v[k][i]]){
					//printf("%d\n",v[k][i]);
					used[v[k][i]]=1;
					dp1[v[k][i]]=dp1[k]+1;
					q.push(v[k][i]);
				}
			}
		}
		aaa:
		if(dp1[b]<=da){
			puts("Alice");continue;
		}
		
		for(i=1;i<=n;i++){
			if(dp1[i]>res){res=dp1[i];tmp=i;}
		}
		
		while(!q.empty()){
			q.pop();
		}
		memset(dp1,0,n*4+10);res=0;
		memset(used,0,n*4+10);
		q.push(tmp);used[tmp]=1;
		while(!q.empty()){
			k=q.front();q.pop();
			for(i=0;i<v[k].size();i++){
				if(!used[v[k][i]]){
					used[v[k][i]]=1;
					dp1[v[k][i]]=dp1[k]+1;
					q.push(v[k][i]);
				}
			}
		}
		
		for(i=1;i<=n;i++){
			if(dp1[i]>res){res=dp1[i];}
		}
		//printf("%d\n",res);
		if(res<=da*2){
			puts("Alice");
		}else{
			puts("Bob");
		}
	}
}