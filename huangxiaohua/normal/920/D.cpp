#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,k,su,a[5050],sb,sb2,op[5050],it,v[5050];
bool vis[5050][5050];

bool dfs(int x,int y){
	if(x==n)return (y==sb);
	if(vis[x][y])return 0;
	vis[x][y]=1;
	if(dfs(x+1,y)){
		return 1;
	}
	op[++it]=x+1;v[x+1]=1;
	if(dfs(x+1,(y+a[x+1])%m)){
		return 1;
	}
	it--;v[x+1]=0;return 0;
}

int main() {
	cin>>n>>m>>k;t=k;
	sb=k%m;
	for(i=1;i<=n;i++){
		cin>>a[i];su+=a[i];
	}
	sb2=sb+((su-sb)/m)*m;
	if(sb2<k||!dfs(0,0)){puts("NO");return 0;}
	puts("YES");
	
	if(!sb){
		for(i=2;i<=n;i++)printf("1000000000 %d 1\n",i);
		if(k>=m)printf("%d 1 2\n",k/m);
		return 0;
	}
	
	for(i=2;i<=it;i++){
		printf("%d %d %d\n",1000000000,op[i],op[1]);
		a[op[1]]+=a[op[i]];
	}
	k=0;
	for(i=1;i<=n;i++){
		if(v[i])continue;
		if(!k)k=i;
		else printf("%d %d %d\n",1000000000,i,k),a[k]+=a[i];
	}
	if(!k){
		k=(op[1]==1)?2:1;
	}
	if(a[k]>=m)printf("%d %d %d\n",a[k]/m,k,op[1]);
	a[op[1]]+=(a[k]/m)*m;
	if((a[op[1]]-t)>=m)printf("%d %d %d\n",(a[op[1]]-t)/m,op[1],k);
}