#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define mid (l+r>>1)
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
typedef long long ll;
using namespace std;
const int N=800010;
int n,L;
ll a[N],b[N];
int chk(int x){
	ll l=1,r=1,mx=-1e9;
	FOR(i,n+1,3*n){
		while(a[l]+x<b[i]&&l<=4*n)++l;
		while(a[r]-x<=b[i]&&r<=4*n)++r;
		mx=max(mx,l-i);
		if(r-i-1<mx)return 0;
	}
	return 1;
}
signed main(){
	scanf("%d%d",&n,&L);
	FOR(i,1,n)scanf("%lld",a+i);
	FOR(i,1,n)scanf("%lld",b+i);
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	FOR(i,1+n,4*n)a[i]=a[i-n]+L,b[i]=b[i-n]+L;
	int l=-1,r=L/2+1;
	while(r-l>1)chk(mid)?r=mid:l=mid;
	printf("%d",r);
	return 0;
}