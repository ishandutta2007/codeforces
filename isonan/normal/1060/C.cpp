#include <cstdio>
#include <iostream>

long long a[2001],b[2001],n,m,x,sa[2001],sb[2001],ans;
long long max(long long a,long long b){
	return a>b?a:b;
}
long long min(long long a,long long b){
	return a<b?a:b;
}
int main(){
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)std::cin>>a[i],a[i]+=a[i-1],sa[i]=100000000000;
	for(int i=1;i<=m;i++)std::cin>>b[i],b[i]+=b[i-1],sb[i]=100000000000;
	std::cin>>x;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			sa[j-i+1]=min(sa[j-i+1],a[j]-a[i-1]);
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
			sb[j-i+1]=min(sb[j-i+1],b[j]-b[i-1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(sa[i]*sb[j]<=x)ans=max(ans,i*j);
	std::cout<<ans;
}