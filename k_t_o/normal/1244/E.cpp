#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;
 
inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 100094
int n,l,r,a[N],mi,ss;
long long Ans,k,s[N],K,_s[N],kk;
int main()
{
	n=read(); cin>>k; K=k;
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);Ans=a[n]-a[1];
	for(int i=n;i;--i)s[i]=s[i+1]+a[i];
	for(int i=1;i<=n;++i)_s[i]=_s[i-1]+a[i];
	for(int i=1;i<=n;++i){
		k-=(long long)(a[i]-a[i-1])*(i-1);
		if(k<0)break;
		l=i;r=n;
		while(l<=r){
			mi=l+r>>1;
			if(s[mi+1]-(long long)(n-mi)*a[mi]<=k)ss=mi,r=mi-1;else l=mi+1;
		}
		kk=k-(s[ss+1]-(long long)(n-ss)*a[ss]);
		Ans=min(Ans,(long long)a[ss]-a[i]-kk/(n-ss+1));
	}
	
//	cerr<<Ans<<endl;
	
	k=K;
	for(int i=n;i;--i){
		k+=(long long)(a[i]-a[i+1])*(n-i);
		if(k<0)break;
		l=1;r=i;
		while(l<=r){
			mi=l+r>>1;
			if((long long)(mi-1)*a[mi]-_s[mi-1]<=k)ss=mi,l=mi+1;else r=mi-1;
		}
		
		kk=k-((long long)(ss-1)*a[ss]-_s[ss-1]);
//		cerr<<ss<<' '<<k<<' '<<kk<<endl;////
		Ans=min(Ans,(long long)a[i]-a[ss]-kk/ss);
	}
	
	Ans=max(Ans,0ll); /// ull
	cout<<Ans;
}