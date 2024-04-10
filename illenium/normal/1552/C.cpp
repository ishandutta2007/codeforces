#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

struct node{int a,b;}p[maxn];
int n,k,v[maxn];
vector <int> vec;

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); k=read(); rep(i,1,2*n) v[i]=0; vec.clear();
		rep(i,1,k)
		{
			p[i].a=read(),p[i].b=read(); v[p[i].a]=1,v[p[i].b]=1;
			if(p[i].a>p[i].b) swap(p[i].a,p[i].b);
		}
		rep(i,1,2*n) if(!v[i]) vec.pb(i);
		sort(vec.begin(),vec.end()); int st=vec.size()/2;
		for(int i=0,j=st;j<vec.size();i++,j++) p[++k].a=vec[i],p[k].b=vec[j];
		
		int ans=0;
		rep(i,1,k) rep(j,i+1,k) if((p[j].a>p[i].a&&p[j].a<p[i].b&&p[j].b>p[i].b)||
			(p[i].a>p[j].a&&p[i].a<p[j].b&&p[i].b>p[j].b)) ans++;
		printf("%d\n",ans);
	}
	return 0;
}