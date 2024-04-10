//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
#define gc (c=getchar())
char readc()
{
	char c;
	while(gc<'-');
	return c;
}
int read()
{
    char c;
    while(gc<'-');
    if(c=='-')
    {
        int x=gc-'0';
        while(gc>='0')x=x*10+c-'0';
        return -x;
    }
    int x=c-'0';
    while(gc>='0')x=x*10+c-'0';
    return x;
}
#undef gc

const int N=1000+5;
bool lk[N][N];
int gs[N],gt[N];
int n,m,s,t;

void get(int s,int *g)
{
	rep(i,1,n)g[i]=N;
	deque<int>q;
	q.push_back(s);g[s]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop_front();
		rep(y,1,n)
		if(g[y]==N&&lk[x][y])
		{
			g[y]=g[x]+1;
			q.push_back(y);
		}
	}
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	n=read();m=read();s=read();t=read();
	rep(i,1,m)
	{
		int x=read(),y=read();
		lk[x][y]=lk[y][x]=1;
	}
	get(s,gs);
	get(t,gt);
	int ans=0;
	rep(x,1,n)
	rep(y,x+1,n)
	if(!lk[x][y]&&min(gs[x]+gt[y],gt[x]+gs[y])+1>=gs[t])++ans;
	cout<<ans<<endl;
}