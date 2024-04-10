#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;

int i,j,k,n,m,t,a[1005000];
ll f[1005000][3],res=1e18,x,y;
bool vis[1005000];

ll chk(int a1,int a2){
	ll sb;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		if(i==a2)continue;
		sb=1e16;
		if(!((a[i]+1)%a1)||!((a[i]-1)%a1))sb=y;
		if(!(a[i]%a1))sb=0;
		f[i][0]=f[i-1][0]+sb;
		f[i][1]=min(f[i-1][1],f[i-1][0])+x;
		f[i][2]=min(f[i-1][2],f[i-1][1])+sb;
	}
	return (a2==1)?min({f[n][0],f[n][1],f[n][2]}):min({f[n-1][0],f[n-1][1],f[n-1][2]});
}

void chk2(int x,int y,int z){
	int i,j,k;
	for(i=2;i*i<=x;i++){
		if(x%i)continue;
		while(!(x%i))x/=i;
		res=min(res,chk(i,y)+z);
	}
	if(x>1)res=min(res,chk(x,y)+z);
}

int main() {
	scanf("%d%d%d",&n,&j,&k);x=j;y=k;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	chk2(a[1],1,0);
	chk2(a[1]+1,1,y);
	chk2(a[1]-1,1,y);
	chk2(a[n],n,0);
	chk2(a[n]-1,n,y);
	chk2(a[n]+1,n,y);
	long long nmsl=res;
	printf("%lld",nmsl);
}