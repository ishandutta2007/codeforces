#include <bits/stdc++.h>
#define ope operator
#define re register
#define il inline
using namespace std;
int T,n,m,k,q;
int a[100010],cnt[200010];
long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
long long lcm(long long x,long long y){
	return x*(y/gcd(x,y));
}
long long ksm(long long a,int k){
	long long ans=1;
	for(;k;k>>=1,a=a*a) if(k&1) ans=ans*a;
	return ans;
}
int main(){
	scanf("%d",&n);
	long long ans=1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int j=2,ed=sqrt(200000);j<=ed;j++){
		int mn1=-1,mn2=-1;
		for(int i=1;i<=n;i++){
			int tmp=0;
			while(a[i]%j==0) a[i]/=j,tmp++;
			if(mn1<0) mn1=tmp;
			else if(tmp<mn1) mn2=mn1,mn1=tmp;
			else if(mn2<0) mn2=tmp;
			else if(tmp<mn2) mn2=tmp;
		}
//		if(mn2) cout<<j<<" "<<mn1<<" "<<mn2<<"\n";
		ans*=ksm(j,mn2);
	}
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	for(int i=2;i<=200000;i++) if(cnt[i]>=n-1) ans*=i;
	printf("%lld\n",ans);
}