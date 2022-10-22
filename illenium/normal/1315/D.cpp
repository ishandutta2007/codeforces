#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n;
struct node{ll val,t;}p[maxn];
multiset <ll> s;
multiset <ll>::iterator it;

inline bool cmp(node a,node b)
{
	if(a.val==b.val) return a.t<b.t;
	else return a.val<b.val;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) p[i].val=read();
	for(int i=1;i<=n;i++) p[i].t=read();
	sort(p+1,p+n+1,cmp);
	//for(int i=1;i<=n;i++) cout<<p[i].val<<" "<<p[i].t<<endl;
	ll tot=0,nw=1,nt=p[1].val,ans=0;
	while(nw<=n||s.size()!=0)
	{
		//cout<<nw<<endl;
		if(nw<=n&&nt==p[nw].val) s.insert(p[nw].t),tot+=p[nw].t;
		while(nt==p[nw+1].val&&nw<=n)
		{
			tot+=p[nw+1].t;
			s.insert(p[nw+1].t); nw++;
		}
		it=s.end(); it--;
		ll tp=*it; tot-=tp; ans+=tot; s.erase(it);
		if(s.size()!=0) nt++; else nt=p[nw+1].val,nw++;
	}
	cout<<ans<<endl;
	return 0;
}