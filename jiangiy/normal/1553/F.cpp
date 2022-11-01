#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=300005,B=512,C=300;
int n,cc,a[N],b[N/B+10],cnt[C+1];
LL ans,sum,c[N],d[N/B+10],ta[C+1];
void add(int x){
	int b=x/B;
	for(int i=b*B;i<=x;i++)a[i]++;
	for(int i=1;i<=b;i++)::b[i]++;
}
int qry(int x){
	return a[x]+b[x/B+1];
}
void add2(int x,int v){
	c[x]+=v;
	d[x/B]+=v;
}
LL qry2(int x){
	int b=x/B;
	LL r=0;
	for(int i=b*B;i<=x;i++)r+=c[i];
	for(int i=0;i<=b-1;i++)r+=d[i];
	return r;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(x<=C){
			ans+=ta[x];
		}
		else{
			LL tmp=0;
			for(int i=1;i<=(N-1)/x;i++)tmp+=qry(i*x);
			ans+=sum-tmp*x;
		}
		for(int j=1;j<=C;j++){
			int t=x%j;
			ta[j]+=t;
			ans+=(LL)cnt[j]*t;
		}
		ans+=(LL)x*cc-qry2(x);
		add(x);
		sum+=x;
		if(x<=C){
			cnt[x]++;
		}
		else{
			cc++;
			for(int i=1;i<=(N-1)/x;i++)add2(i*x,x);
		}
		printf("%lld ",ans);
	}
}