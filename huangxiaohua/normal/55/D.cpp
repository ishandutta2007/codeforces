#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-2))
int i,j,k,n,m,t,p[30][20],lcm[2550][11],sb=1;
ll f[21][2550][260],a[21],l,r;
bool chk[2550][260];
ll dp(int dep,int up,int x,int y){
	if(x>=2520){x-=2520;}
	if(!dep){return chk[x][y];}
	if(!up&&~f[dep][x][y]){return f[dep][x][y];}
	ll res=0;
	for(int i=0;i<=9;i++){
		if(up&&i>a[dep]){continue;}
		if(i<=1){res+=dp(dep-1,(i==a[dep])&up,x+p[dep-1][i],y);}
		else{res+=dp(dep-1,(i==a[dep])&up,x+p[dep-1][i],y|b(i));}
	}
	if(!up){f[dep][x][y]=res;}
	return res;
}
ll get(ll x){
	memset(f,-1,sizeof(f));
	for(i=1;i<=19;i++){a[i]=x%10;x/=10;}
	return dp(19,1,0,0);
}
int main(){
	for(i=0;i<=2520;i++){
		for(j=0;j<=255;j++){
			chk[i][j]=1;
			for(k=2;k<=9;k++){
				if(b(k)&j&&i%k){chk[i][j]=0;break;}
			}
		}
	}
	for(i=0;i<=20;i++){
		for(j=1;j<=9;j++){p[i][j]=sb*j%2520;}sb=sb*10%2520;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",get(r)-get(l-1));
	}
}