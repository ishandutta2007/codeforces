#include <bits/stdc++.h>
using namespace std;
 
int n,i,t,j,res[100500],res2[100500],x,y,son[100500],used[100500],mn,un;
int ans1,ans2;
vector<int> v[100500];
queue<int> q;
 
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);mn=1145141919;
		ans1=ans2=un=0;
		memset(res,0,n*4+10);
		memset(son,0,n*4+10);
		memset(used,0,n*4+10);
		
		for(i=1;i<=n;i++){
			v[i].clear();res2[i]=1;
		}
		while(!q.empty()){
			q.pop();
		}
		for(i=1;i<=n-1;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
			son[x]++;son[y]++;
		}
		for(i=1;i<=n;i++){
			if(son[i]==1){q.push(i);used[i]=1;}
		}
		while(!q.empty()){
			
			x=q.front();q.pop();
			used[x]=1;un++;
			for(i=0;i<v[x].size();i++){
				son[v[x][i]]--;
				if(!used[v[x][i]]&&son[v[x][i]]==1){
					q.push(v[x][i]);
				}
				if(!used[v[x][i]]&&un!=n-1){
					res[v[x][i]]+=res[x]+1;
					res2[v[x][i]]=max(res2[v[x][i]],res[x]+1);
				}
				if(!used[v[x][i]]&&un==n-1){
					res2[v[x][i]]=max(res2[v[x][i]],res[x]+1);
				}
			}
			
		}
		
		for(i=1;i<=n;i++){
			res[i]=max(res2[i],n-1-res[i]);
			mn=min(mn,res[i]);
		}
		
		for(i=1;i<=n;i++){
			//printf(" %d %d %d\n",i,res[i],res2[i]);
			if(res[i]==mn){
				if(!ans1){ans1=i;continue;}
				else{ans2=i;}
			}
		}
		if(!ans2){
			printf("%d %d\n%d %d\n",ans1,v[ans1][1],ans1,v[ans1][1]);
		}
		else{
			for(j=0;j<v[ans1].size();j++){
				if(v[ans1][j]==ans2){continue;}
				printf("%d %d\n%d %d\n",ans1,v[ans1][j],ans2,v[ans1][j]);break;
		}
	}
}
}