#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=1e6+5,mod=998244353;
#define inf 0x3f3f3f3f
int n,m;
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
  	// freopen("1.in","r",stdin);
    int t=1;
	sc(t);
	while(t--)
	{
		sc(n,m);
		char s[n+3][m+3];
		memset(s,'#',sizeof('#'));
		rep(i,1,n)
			sc(s[i]+1);
		int d[n+3][m+3];
		int x,y;
		memset(d,0,sizeof(d));
		rep(i,1,n)
			rep(j,1,m)
		{
			if(s[i][j]=='L') x=i,y=j;
			rep(k,0,3)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<1||x>n||y<1||y>m) continue;
				if(s[i][j]!='#'&&s[x][y]!='#') d[i][j]++;
			}
		}
		bool del[n+3][m+3];
		memset(del,false,sizeof(del));
		del[x][y]=true;
		queue<pair<int,int>>q;
		q.push({x,y});
		while(!q.empty())
		{
			x=q.front().first;y=q.front().second;q.pop();
			for(int i=0;i<4;i++)
			{
				int xx=x+dx[i];
				int yy=y+dy[i];
				if(xx<1||xx>n||yy<1||yy>m||s[xx][yy]=='#'||del[xx][yy]) continue;
				d[xx][yy]--;
				if(d[xx][yy]<=1) q.push({xx,yy}),del[xx][yy]=true,s[xx][yy]='+';
			}
		}
		for(int i=1;i<=n;i++) puts(s[i]+1);
	}
}
/*
....#
L##..
....#
*/