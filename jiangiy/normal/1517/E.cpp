#include<bits/stdc++.h>
#define fi first
#define se second
#define ULL unsigned long long
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=200010,P=998244353;
int n,s[N],f[N];
LL ans,p[N];
std::pair<LL,int>a[N],b[N];
void add(int x){
	for(;x<=n;x+=x&-x)f[x]++;
}
int qry(int x){
	int r=0;
	for(;x;x&=x-1)r+=f[x];
	return r;
}
void work(bool u){
	LL tsum=0;
	for(int i=1;i<=n;i++) if((i&1)==u)tsum+=s[i];
	else tsum-=s[i];
	LL sp=0,sc=0;
	int ac=0,bc=0;
	if(u==1){
		sc-=s[1]*2;
	}
	else{
		sp+=s[1]*2;
		a[ac++]=MP(sc,1);
	}
	for(int i=2;i<=n;i++){
		if((i&1)==u){
			sc-=s[i]*2,sp-=s[i]*2;
			if(i==n&&sc+tsum>0)ans++;
			if(i==n&&sp+tsum>0)ans++;
		}
		else{
			a[ac++]=MP(sc,i);
			a[ac++]=MP(sp,i);
		}
	}
	sp=0,sc=0;
	if((n&1)==u){
		sc-=s[n]*2;
		b[bc++]=MP(sp,n);
	}
	else{
		sp+=s[n]*2;
	}
	for(int i=n-1;i;i--){
		if((i&1)!=u){
			sc+=s[i]*2,sp+=s[i]*2;
		}
		else{
			b[bc++]=MP(sc,i);
			b[bc++]=MP(sp,i);
		}
	}
	std::sort(a,a+ac);
	std::sort(b,b+bc);
	for(int i=1;i<=n;i++)f[i]=0;
	int j=ac;
	for(int i=0;i<bc;i++){
		for(;j&&a[j-1].fi+b[i].fi+tsum>0;){
			j--;
			add(a[j].se);
		}
		ans+=qry(b[i].se);
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	if(n==1){
		puts("1");
		return;
	}
	for(int i=1;i<=n;i++)p[i]=p[i-1]+s[i];
	ans=0;
	for(int i=2;i<=n;i++){
		if(p[i]-(p[n]-p[i])>0)ans++;
	}
	work(0);
	work(1);
	printf("%lld\n",ans%P);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
}