#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=1e6+7;
int T,n,a[N],b[N],p[N],len,s;
ll ans;
void solve(){
	scanf("%d",&n),s=ans=0;
	FOR(i,1,n)scanf("%d",a+i);
	FOR(i,1,n)scanf("%d",b+i),p[b[i]]=a[i];
	FOR(i,1,n)if(a[i]){
		len=0;
	    for(int x=i;a[x];x=p[x])a[x]=0,++len;
	    s+=len/2;
	}
	--n;
	while(n>0&&s>0)ans+=n,n-=2,--s;
	printf("%lld\n",ans*2);
}
signed main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}