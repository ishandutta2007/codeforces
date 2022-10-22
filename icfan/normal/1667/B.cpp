#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=500000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
ll sum[Maxn+5];
ll d[Maxn+5],d_len;
namespace BIT{
	int f[Maxn+5];
	void init(){
		for(int i=1;i<=d_len;i++){
			f[i]=-Inf;
		}
	}
	void add(int x,int a){
		for(int i=x;i<=d_len;i+=(i&(-i))){
			f[i]=std::max(f[i],a);
		}
	}
	int query(int x){
		int ans=-Inf;
		for(int i=x;i>0;i-=(i&(-i))){
			ans=std::max(ans,f[i]);
		}
		return ans;
	}
}
int val[Maxn+5];
int f[Maxn+5];
void solve(){
	d_len=0;
	scanf("%d",&n);
	d[++d_len]=0;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		d[++d_len]=sum[i];
	}
	std::sort(d+1,d+1+d_len);
	d_len=std::unique(d+1,d+1+d_len)-d-1;
	BIT::init();
	sum[0]=std::lower_bound(d+1,d+1+d_len,0ll)-d;
	BIT::add(sum[0],0);
	for(int i=1;i<=d_len;i++){
		val[i]=-Inf;
	}
	val[sum[0]]=0;
	for(int i=1;i<=n;i++){
		sum[i]=std::lower_bound(d+1,d+1+d_len,sum[i])-d;
		f[i]=f[i-1]-1;
		f[i]=std::max(f[i],val[sum[i]]);
		f[i]=std::max(f[i],BIT::query(sum[i]-1)+i);
		val[sum[i]]=std::max(val[sum[i]],f[i]);
		BIT::add(sum[i],f[i]-i);
	}
	printf("%d\n",f[n]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}