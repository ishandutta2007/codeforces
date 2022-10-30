#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,lg[400500],ty;
int fa[400500][21],fa2[400500][21],dep[400500];
ll lst,w[400500],x,y,cur,f[400500],st[400500][21];

int main(){
	n=1;
	for(i=1;i<=400005;i++){lg[i]=lg[i>>1]+1;}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&ty);
		if(ty==1){
			scanf("%lld%lld",&x,&y);
			x^=lst;y^=lst;
			w[++n]=y;
			fa[n][0]=x;
			st[n][0]=y;
			for(i=1;i<=19;i++){
				fa[n][i]=fa[fa[n][i-1]][i-1];
				st[n][i]=max(st[n][i-1],st[fa[n][i-1]][i-1]);
			}
			cur=n;
			for(i=19;i>=0;i--){
				if(st[fa[cur][0]][i]<y){
					cur=fa[cur][i];
				}
			}
			cur=fa[cur][0];
			fa2[n][0]=cur;
			dep[n]=dep[cur]+1;
			f[n]=w[n]+f[cur];
			
			for(i=1;i<=19;i++){
				fa2[n][i]=fa2[fa2[n][i-1]][i-1];
			}
		}
		else{
			scanf("%lld%lld",&x,&y);
			x^=lst;y^=lst;
			if(y<w[x]){
				lst=0;puts("0");continue;
			}
			cur=x;
			for(i=20;i>=0;i--){
				if(!fa2[cur][i]){continue;}
				if(f[x]-f[fa2[cur][i]]+w[fa2[cur][i]]<=y){
					cur=fa2[cur][i];
				}
			}
			lst=dep[x]-dep[cur]+1;
			printf("%lld\n",lst);
		}
	}
}