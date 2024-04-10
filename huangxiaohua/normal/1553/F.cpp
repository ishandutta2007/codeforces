#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,r;

ll f1[300500],f2[300500],res,pre;

void add(ll *a,ll x,ll y){for(;x<=300000;x+=(-x&x)){a[x]+=y;}}
ll get(ll *a,ll x,ll y=0){for(;x;x-=(-x&x)){y+=a[x];}return y;}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		pre+=k;res+=pre+1ll*k*(i-1);
		add(f2,k,1);
		res-=get(f1,k);
		for(j=k;j<=300000;j+=k){
			r=min(300000,j+k-1);
			res-=(j/k)*(get(f2,r)-get(f2,j-1))*k;
			add(f1,j,k);
		}
		printf("%lld\n",res);
	}
}