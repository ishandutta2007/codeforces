#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=200005,P=998244353;
int n,x[N],y[N],s[N],p[N];
PI v[N*2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",x+i,y+i,s+i);
	for(int i=1;i<=n;i++){
		v[i*2]=MP(x[i],i);
		v[i*2-1]=MP(y[i],-i);
	}
	std::sort(v+1,v+n*2+1);
	int cur=1,ans=0;
	v[n*2+1].fi=x[n]+1;
	for(int i=n*2;i;i--){
		int j=std::abs(v[i].se),d=v[i+1].fi-v[i].fi;
		ans=(ans+(LL)d*cur)%P;
		if(v[i].se>0){
			int nc=((LL)s[j]+cur*2+P-1)%P;
			int r=((LL)s[j]+cur+P-1)%P;
			p[j]=r;
			cur=nc;
		}
		else{
			cur=(cur+P-p[j])%P;
		}
	}
	ans=(ans+(LL)cur*v[1].fi)%P;
	printf("%d\n",ans);
}