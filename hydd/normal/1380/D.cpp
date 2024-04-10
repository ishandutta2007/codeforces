#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x,k,y;
int a[210000],pos[210000],b[210000];
ll calc(int l,int r,int v){
	if (l>r) return 0;
	bool flag=false;
	for (int i=l;i<=r;i++) flag|=(a[i]>=v);
	int len=r-l+1;
	if (flag){
		if (len<k) return -1;
		else return min(x+1ll*(len-k)*y,1ll*len/k*x+1ll*(len%k)*y);
	} else{
		if (len<k) return 1ll*y*len;
		else return min(1ll*y*len,min(x+1ll*(len-k)*y,1ll*len/k*x+1ll*(len%k)*y));
	}
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&x,&k,&y);
	a[0]=0; a[n+1]=0; int t;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
	for (int i=1;i<=m;i++) scanf("%d",&t),b[i]=pos[t];

	b[0]=0; b[m+1]=n+1;
	ll ans=0;
	for (int i=1;i<=m+1;i++){
		ll tmp=calc(b[i-1]+1,b[i]-1,max(a[b[i-1]],a[b[i]]));
		if (b[i-1]>=b[i]||tmp==-1){ puts("-1"); return 0;}
		ans+=tmp;
	}
	printf("%lld\n",ans);
	return 0;
}