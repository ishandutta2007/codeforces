#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t;
ll x,y,d[1050],a[1050],n,m,l,r,md,res=1e10;

bool chk(int x){
	ll res=0;
	int i,j,k;
	for(i=1;i<=n;i++){
		if(d[i]<=d[x]){res+=a[i];}
	}
	return res>=m;
}

int main(){
	scanf("%lld%lld",&n,&m);m=1000000-m;
	for(i=1;i<=n;i++){
		scanf("%lld%lld%lld",&x,&y,&a[i]);
		d[i]=x*x+y*y;
		l+=a[i];
	}
	if(l<m){puts("-1");return 0;}
	for(i=1;i<=n;i++){
		if(chk(i)){res=min(res,d[i]);}
	}
	printf("%.20lf",sqrt(res));
}