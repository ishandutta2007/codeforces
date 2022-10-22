#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const int Mod=998244353;
int n;
int a[Maxn+5];
ll s[Maxn+5],g[Maxn+5];
ll f[Maxn+5],h[Maxn+5];
ll d[Maxn+5];
int d_len;
struct BIT{
	int f[Maxn+5];
	void init(){
		for(int i=0;i<=d_len;i++){
			f[i]=0;
		}
	}
	void add(int x,int a){
		for(int i=x;i>0;i-=(i&(-i))){
			f[i]+=a;
		}
	}
	int query(int x){
		int ans=0;
		for(int i=x;i<=d_len;i+=(i&(-i))){
			ans+=f[i];
		}
		return ans;
	}
}tr[2];
int calc(ll t,int s_id,int t_id){
	int ans=0;
	d_len=0;
	t=g[1]+g[n-1]-t-1;
	for(int i=s_id-1;i<=t_id;i++){
		d[++d_len]=t-f[i];
	}
	std::sort(d+1,d+1+d_len);
	d_len=std::unique(d+1,d+1+d_len)-d-1;
	tr[0].init(),tr[1].init();
	for(int i=s_id-1;i<=t_id;i++){
		ll x=t-f[i];
		int id_x=std::lower_bound(d+1,d+1+d_len,x)-d;
		tr[i&1].add(id_x,1);
		int id_y=std::lower_bound(d+1,d+1+d_len,h[i])-d;
		ans=(ans+tr[i&1].query(id_y))%Mod;
	}
	return ans;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		g[i]=g[i-1]+a[i];
		s[i]=(i-2>=0?s[i-2]:0)+a[i];
		f[i]=g[i]-s[i]+s[i-1];
		h[i]=g[i]+s[i]-s[i-1];
	}
	if(n==1){
		puts("1");
		return;
	}
	int ans=0;
	for(int i=0;i<4;i++){
		ll t=0;
		if(i&1){
			t+=a[1];
		}
		else{
			t-=a[1];
		}
		if(i&2){
			t+=a[n];
		}
		else{
			t-=a[n];
		}
		ans=(ans+calc(t,3-(i&1),n-1-((i>>1)&1)))%Mod;
	}
	for(int i=n+1;i>0;i--){
		if(g[n]-g[i-1]<g[i-1]){
			ans=(ans+1)%Mod;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}