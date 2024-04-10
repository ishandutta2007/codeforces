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

ll b[maxn],tot,cnt,n,c[maxn],c3[maxn],c1,c2,ans;
struct node{int a,v;}p[maxn],p1[maxn],p2[maxn];

inline bool cp(node a,node b)
{
	if(a.v!=b.v) return a.v<b.v;
	else return a.a<b.a;
}

inline bool cp2(node a,node b)
{
	if(a.v!=b.v) return a.v>b.v;
	else return a.a<b.a;
}

inline void add(int x,ll val){for(int i=x;i<=tot;i+=i&-i) c[i]+=val,c3[i]++;}
inline ll q(int x){ll res=0; for(int i=x;i;i-=i&-i) res+=c[i]; return res;}
inline ll q2(int x){ll res=0; for(int i=x;i;i-=i&-i) res+=c3[i]; return res;}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) p[i].a=read(),b[++cnt]=p[i].a;
	for(int i=1;i<=n;i++) p[i].v=read();
	for(int i=1;i<=n;i++)
	{
		if(p[i].v>=0) p1[++c1].a=p[i].a,p1[c1].v=p[i].v;
		else p2[++c2].a=p[i].a,p2[c2].v=-p[i].v;
	}
	sort(b+1,b+cnt+1); tot=unique(b+1,b+cnt+1)-b-1;
	sort(p1+1,p1+c1+1,cp);
	for(int i=1;i<=c1;i++)
	{
		int x=lower_bound(b+1,b+tot+1,p1[i].a)-b; //cout<<q2(x)<<" "<<p1[i].a<<endl<<endl<<endl;
		ans+=q2(x)*p1[i].a-q(x); add(x,p1[i].a);
	}
	//cout<<ans<<endl;
	
	sort(p2+1,p2+c2+1,cp2);
	for(int i=1;i<=tot;i++) c[i]=0,c3[i]=0;
	for(int i=1;i<=c2;i++)
	{
		int x=lower_bound(b+1,b+tot+1,p2[i].a)-b;
		ans+=q2(x)*p2[i].a-q(x); add(x,p2[i].a);
	}
	//cout<<ans<<endl;
	
	for(int i=1;i<=tot;i++) c[i]=0,c3[i]=0;
	for(int i=1;i<=c2;i++)
	{
		int x=lower_bound(b+1,b+tot+1,p2[i].a)-b;
		add(x,p2[i].a);
	}
	for(int i=1;i<=c1;i++)
	{
		int x=lower_bound(b+1,b+tot+1,p1[i].a)-b;
		ans+=q2(x)*p1[i].a-q(x); //cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}