//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
long long o,l,r,n,k,mi;

inline long long qu(long long p)
{
	if(p>n)return 0;
	long long Ans=0,op,ss;
	if(!(p&1))Ans=qu(p+1);
	for(int i=0;i<=60;++i){
		if(p*(1ll<<i)>n)break;
//		op=p&(-p);
		ss=p*(1ll<<i);
		if(ss+(1ll<<i)-1<=n){
			Ans+=1ll<<i;
			continue;
		}
		Ans+=n-ss+1;
		break;
	}
	return Ans;
}

int main()
{
	cin>>n>>k;	
	l=1;r=n/2;
	while(l<=r){
		mi=(l+r)/2;
		if(qu(mi*2)>=k)o=mi,l=mi+1;else r=mi-1;
	}
	o<<=1;
	if(qu(o+1)>=k)++o; 
	cout<<o;
}