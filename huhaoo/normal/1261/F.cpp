/***************************************************************
	File name: F.cpp
	Author: huhao
	Create time: Wed 27 Nov 2019 03:17:00 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define i64 long long
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
i64 read()
{
	i64 r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
#include<set>
#include<vector>
#include<assert.h>
#define pii pair<i64,i64>
const int N=6010,mod=998244353;
i64 n,m,ans,r;
vector<pii> c,a[N],b[N];
set<pii> s;
#define fp(...) fprintf(stderr,__VA_ARGS__)
void insert(set<pii> &s,pii a)
{
	auto it=s.upper_bound(pii(a.first,(~0ull)>>1));
	if(it!=s.begin())
	{
		it--;
		if(it->first<=a.first&&it->second>=a.second) return;
	}
	it=s.lower_bound(pii(a.first,0));
	while(it!=s.end()&&a.first<=it->first&&a.second>=it->second) it=s.erase(it);
	s.insert(a);
	assert(s.size()<=200000);
}
int main()
{
	n=read();
	fr(i,1,n)
	{
		i64 l=read(),r=read();
		while(r-l>=(l&(-l))-1)
		{
			a[i].push_back(pii(l,l+(l&(-l))-1));
			l+=l&(-l);
		}
		fd(j,60,0) if(r-l+1>=(1ll<<j))
		{
			a[i].push_back(pii(l,l+(1ll<<j)-1));
			l+=(1ll<<j);
		}
	}
	m=read();
	fr(i,1,m)
	{
		i64 l=read(),r=read();
		while(l+(l&(-l))-1<=r)
		{
			b[i].push_back(pii(l,l+(l&(-l))-1));
			l+=l&(-l);
		}
		fd(j,60,0) if(r-l+1>=(1ll<<j))
		{
			b[i].push_back(pii(l,l+(1ll<<j)-1));
			l+=(1ll<<j);
		}
	}
	fr(i,1,n) fr(j,1,m)
	{
		s.clear();
		for(auto A:a[i]) for(auto B:b[j])
		{
			i64 w=max(A.second-A.first,B.second-B.first);
			insert(s,pii((A.first^B.first)&(~w),(A.first^B.first)|w));
		}
		for(auto S:s) c.push_back(S);
	}
	sort(c.begin(),c.end(),[](pii a,pii b){ return a.first==b.first?a.second>b.second:a.first<b.first; });
	for(auto C:c) if(C.second>r) { ans=(ans+((C.second-C.first+1)%mod)*((C.first+C.second)%mod)%mod*((mod+1)/2))%mod; r=C.second; }
	printf("%d\n",(int)ans);
	return 0;
}