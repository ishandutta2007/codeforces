#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll M=2e5+9;
ll n,m,ans,sum;
ll read(){
	ll rex=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rex=rex*10+ch-'0';ch=getchar();}
	return rex*f;
}
struct P{
	ll co,val;
}a[M];
ll b[M];
bool cmp(const P&l,const P&r){
	return l.co==r.co?l.val>r.val:l.co<r.co;
}
int main(){
	n=read(),m=read();
	for(ll i=1;i<=n;++i){
		a[i].co=read();a[i].val=read();
	}
	sort(a+1,a+n+1,cmp);
	a[0].co=0;
	for(ll i=1;i<=n;++i){
		if(a[i].co!=a[i-1].co)ans=a[i].val,sum=1;
		else ans+=a[i].val,sum++;
		b[sum]+=max(ans,0LL);
	}
	ans=0;
	for(ll i=1;i<=n;++i)ans=max(ans,b[i]);
	printf("%I64d\n",ans);
	return 0;
}
/*
5 1
1 1
1 2
1 3
1 4
1 5
*/