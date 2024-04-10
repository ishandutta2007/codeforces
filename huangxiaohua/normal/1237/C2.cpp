#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,vis[50050],res,it,it2;

struct sb{
	int x,y,z,id;
	bool operator<(const sb a)const{
		if(a.x==x){
			if(a.y==y){return a.z>z;}
			else{return a.y>y;}
		}
		return a.x>x;
	}
}s[50050],tmp[50050],tmp2[50050];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].z);
		s[i].id=i;
	}
	sort(s+1,s+n+1);
	vis[n+1]=vis[0]=1;
	for(i=1;i<=n;i++){
		if(vis[i]||vis[i+1]){continue;}
		if(s[i].x==s[i+1].x&&s[i].y==s[i+1].y){printf("%d %d\n",s[i].id,s[i+1].id);vis[i]=vis[i+1]=1;}
	}
	for(i=1;i<=n;i++){
		if(vis[i]){continue;}
		for(j=i+1;j<=n;j++){
			if(!vis[j]){break;}
		}
		if(j==(n+1)){break;}
		if(s[i].x==s[j].x){vis[i]=vis[j]=1;printf("%d %d\n",s[i].id,s[j].id);i=j;}
		else{i=j-1;}
	}
	for(i=1;i<=n;i++){
		if(vis[i]){continue;}
		for(j=i+1;j<=n;j++){
			if(!vis[j]){break;}
		}
		if(j==(n+1)){break;}
		vis[i]=vis[j]=1;printf("%d %d\n",s[i].id,s[j].id);
		i=j;
	}
}