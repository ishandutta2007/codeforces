#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],f[200500],vis[200500],x,y,f2[200500],mx[200500];
int ans;
vector<int> v[200500];
queue<int> q;

struct sb{
	int id,x,y,w;
	bool operator<(const sb a)const{return w<a.w;}
}s[200500];

int main(){
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=t;i++){
		scanf("%d",&s[i].id);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	q.push(1);vis[1]=1;
	while(!q.empty()){
		x=q.front();q.pop();
		for(auto i:v[x]){
			if(!vis[i]){f[i]=f[x]+1;vis[i]=1;q.push(i);}
		}
	}
	memset(vis,0,sizeof(vis));
	q.push(n);vis[n]=1;
	while(!q.empty()){
		x=q.front();q.pop();
		for(auto i:v[x]){
			if(!vis[i]){f2[i]=f2[x]+1;vis[i]=1;q.push(i);}
		}
	}
	for(i=1;i<=t;i++){
		s[i].x=f[s[i].id];
		s[i].y=f2[s[i].id];
		s[i].w=s[i].x-s[i].y;
	}
	sort(s+1,s+t+1);
	for(i=t;i>=1;i--){
		mx[i]=max(mx[i+1],s[i].y);
	}
	for(i=1;i<t;i++){
		//printf("%d %d %d %d %d\n",s[i].id,s[i].x,s[i].y,mx[i+1],s[i].w);
		ans=max(ans,s[i].x+mx[i+1]);
	}
	printf("%d",min(ans+1,f[n]));
}