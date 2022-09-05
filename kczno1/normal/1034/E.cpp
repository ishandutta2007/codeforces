#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=21,U=1<<21;
int n,u;
int cnt1[U];
char s[U+5];
u64 a[2][U],c[U];
u64 ou;
u64 sum(u64 a,u64 b)
{
	return a^b^((a&b&ou)<<1);
}
u64 del(u64 a,u64 b)
{
	return sum(sum(a,~b),ou);
}
u64 mul(u64 a,u64 b)
{
	u64 ans=0;
	for(;b;b>>=2,a<<=2)
	{
		if(b&1)ans=sum(ans,a);
		if(b&2)ans=sum(ans,(a&ou)<<1);
	}
	return ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	rep(i,0,63)
	if(i%2==0)ou|=1ULL<<i;
	cin>>n;
	u=(1<<n)-1;
	rep(i,1,u)cnt1[i]=cnt1[i-(i&-i)]+1;
	rep(d,0,1)
	{
		scanf("%s",s);
		rep(i,0,u)a[d][i]=u64(s[i]-'0')<<cnt1[i]*2;
		rep(i,0,n-1)
		rep(s,0,u)
		if(s&(1<<i))a[d][s]=sum(a[d][s],a[d][s-(1<<i)]);
	}
	rep(s,0,u)c[s]=mul(a[0][s],a[1][s]);
	rep(i,0,n-1)
	rep(s,0,u)
	if(s&(1<<i))c[s]=del(c[s],c[s-(1<<i)]);
	rep(s,0,u)putchar(((c[s]>>cnt1[s]*2)&3)+'0');
}