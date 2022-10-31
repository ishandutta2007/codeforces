#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,fa[200500],a[100500],b[100500],x,y;
ll res,sum;

int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
struct sb{int x,y,w;bool operator<(const sb a)const{return w<a.w;}};
priority_queue<sb> q;

int main(){
	for(i=1;i<=200000;i++){fa[i]=i;}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		for(j=1;j<=k;j++){
			scanf("%d",&x);
			sum+=a[i]+b[x];
			q.push({x,m+i,a[i]+b[x]});
		}
	}
	while(!q.empty()){
		x=find(q.top().x);y=find(q.top().y);k=q.top().w;q.pop();
		if(x==y){continue;}
		fa[fa[x]]=fa[y];res+=k;
	}
	printf("%lld",sum-res);
}