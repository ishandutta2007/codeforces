#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 300005
#define inf 1e9
#define ins insert
#define pb push_back
#define vi vector <int>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

struct node{ll nxt[2],w;}t[maxn*30];
ll n,k,a[maxn],ct,Q,cnt,ANS;

inline void ins(int u,int x,int dep)
{
	t[u].w++; if(dep==-1) return;
	int tmp; if(x&(1<<dep)) tmp=1; else tmp=0;
	if(!t[u].nxt[tmp]) t[u].nxt[tmp]=++ct;
	ins(t[u].nxt[tmp],x,dep-1);
}

inline void query(int u,int x,int dep)
{
	int tmp; if(x&(1<<dep)) tmp=1; else tmp=0;
	//cout<<Q<<" "<<u<<" "<<x<<" "<<dep<<" "<<tmp<<" "<<t[u].nxt[tmp^1]<<endl;
	if(dep==-1) return;
	if(t[u].nxt[tmp^1]) Q+=(1<<dep),query(t[u].nxt[tmp^1],x,dep-1);
	else query(t[u].nxt[tmp],x,dep-1);
}

map <int,int> p,pos;
vector <int> vec[maxn],ans;

int main()
{
	n=read(); k=read(); rep(i,1,n) a[i]=read(),pos[a[i]]=i;
	if(!k)
	{
		cout<<n<<endl;
		rep(i,1,n) printf("%d ",i);
		return 0;
	}
	int nw=1,q=0; while(nw<=k) nw<<=1,q++;
	rep(i,1,n)
	{
		int tmp=a[i]>>q; if(!p[tmp]) p[tmp]=++cnt;
		int q=p[tmp]; vec[q].pb(a[i]);
	}
	rep(i,1,cnt)
	{
		//cout<<i<<" "<<vec[i].size()<<endl;
		if(vec[i].size()==1) ans.pb(pos[vec[i][0]]);
		else
		{
			int F=0;
			for(auto x:vec[i]) ins(0,x,31);
			for(auto x:vec[i])
			{
				Q=0; query(0,x,31); //cout<<x<<" "<<Q<<endl;
				if(Q>=k){ans.pb(pos[x]),ans.pb(pos[x^Q]); F=1; break;}
			}
			if(!F) ans.pb(pos[vec[i][0]]);
			rep(j,0,ct) t[j].nxt[0]=0,t[j].nxt[1]=0,t[j].w=0; ct=0;
		}
	}
	if(ans.size()<2) puts("-1");
	else
	{
		cout<<ans.size()<<endl;
		for(auto x:ans) printf("%d ",x);
	}
	return 0;
}