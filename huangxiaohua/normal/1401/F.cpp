#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,x,y,ty;
ll res,f[2005000],a[2005000];
bool swp[25];
void add(int x,ll y){for(;x<=b(n+1);x+=(-x&x)){f[x]+=y;}}
ll get2(int x,ll y=0){for(;x;x-=(-x&x)){y+=f[x];}return y;}
ll get(int x,ll y=0){
	if(x<0){return 0;}
	int i,j,k,xx=x,l,r;
	for(i=1,j=x;i<=n;i++){
		if(swp[i]){j^=b(i);}
	}
	y+=a[j+1];
	for(;x;x-=(-x&x)){
		k=__builtin_ffs(x);
		l=x-(-x&x);r=x-1;
		for(i=k;i<=n;i++){
			if(swp[i]){l^=b(i);r^=b(i);}
		}
		l++;r++;
		y+=get2(r)-get2(l-1);
	}
	return y;
}

int main() {
    scanf("%d%d",&n,&t);
    for(i=1;i<=b(n+1);i++){
    	scanf("%lld",&a[i]);
    	add(i,a[i]);
	}
	while(t--){
		scanf("%d",&ty);
		if(ty==1){
			scanf("%d%d",&x,&y);x--;
			for(i=1;i<=n;i++){if(swp[i]){x^=b(i);}}x++;
			add(x,-a[x]);a[x]=y;add(x,y);
		}
		if(ty==2){
			scanf("%d",&k);
			for(i=1;i<=k;i++){swp[i]^=1;}
		}
		if(ty==3){
			scanf("%d",&k);swp[k+1]^=1;
		}
		if(ty==4){
			scanf("%d%d",&x,&y);x--;y--;
			printf("%lld\n",get(y)-get(x-1));
		}
	}
}