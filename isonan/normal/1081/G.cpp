#include <cstdio>
#define int long long

int n,k,q,t1,t2,cnt1,cnt2,inv4,inv2,inv[200001];
long long ans;
inline int mul(const int &a,const int &b){return 1ll*a*b%q;}
inline int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
void merge(int l,int r,int k){
	if(l<r){
		if(k<=1){
			if(t1==r-l+1)++cnt1;
			else if(t2==r-l+1)++cnt2;
			else if(!t1)t1=r-l+1,cnt1=1;
			else t2=r-l+1,cnt2=1;
			(ans+=mul(mul(r-l+1,r-l),inv4))%=q;
			return;
		}
		merge(l,(l+r)>>1,k-1);
		merge(((l+r)>>1)+1,r,k-1);
	}
	else{
		{
			if(t1==r-l+1)++cnt1;
			else if(t2==r-l+1)++cnt2;
			else if(!t1)t1=r-l+1,cnt1=1;
			else t2=r-l+1,cnt2=1;
			(ans+=mul(mul(r-l+1,r-l),inv4))%=q;
			return;
		}
	}
}
int getans(int n,int m){
	int ans=0;
	(ans+=mul(inv2,mul(n,m)))%=q;
	for(int i=1;i<=n;i++)
		(ans+=(inv[i]-inv[i+m]+q))%=q;
	return ans;
}
signed main(){
	scanf("%I64d%I64d%I64d",&n,&k,&q);
	inv4=qsm(4,q-2);
	inv2=(q+1)>>1;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=mul(q-q/i,inv[q%i]);
	for(int i=1;i<=n;i++)(inv[i]+=inv[i-1])%=q;
	merge(1,n,k);
	(ans+=mul(getans(t1,t1),mul(mul(cnt1,cnt1-1),inv2)))%=q;
	(ans+=mul(getans(t2,t2),mul(mul(cnt2,cnt2-1),inv2)))%=q;
	(ans+=mul(getans(t1,t2),mul(cnt1,cnt2)))%=q;
	printf("%I64d",ans);
}