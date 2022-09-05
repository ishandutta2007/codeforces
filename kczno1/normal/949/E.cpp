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

const int N=1e5+5,L=20;
bool qa[N*2*L],*tot=qa;
bool *a[L];
int ans,ansb[L];

int b[L];
void dfs(int dep,int mn,int mx,int cnt)
{
	if(cnt>=ans)return ;
	if(mn==0&&mx==0)
	{
		ans=cnt;
		memcpy(ansb,b,sizeof(b));
		return ;
	}
		
	rep(i,mn,mx)
	if(i%2&&a[dep][i])goto End;
	memset(a[dep+1]+mn,0,(mx-mn+1)*sizeof(*a));
	rep(i,mn,mx)
	if(a[dep][i])a[dep+1][i/2]=1;
	b[dep]=0;dfs(dep+1,mn/2,mx/2,cnt);
	return ;
	End: ;

#define F(i) ((i%2==0)?(i/2):((i+1)/2))
	if(!(F(mn)==mn&&F(mx)==mx))
	{
		memset(a[dep+1]+F(mn),0,(F(mx)-F(mn)+1)*sizeof(*a[0]));
		rep(i,mn,mx)
		if(a[dep][i])a[dep+1][F(i)]=1;
		b[dep]=-1;dfs(dep+1,F(mn),F(mx),cnt+1);
	}
#undef F
#define F(i) ((i%2==0)?(i/2):((i-1)/2))
	if(!(F(mn)==mn&&F(mx)==mx))
	{
		memset(a[dep+1]+F(mn),0,(F(mx)-F(mn)+1)*sizeof(*a[0]));
		rep(i,mn,mx)
		if(a[dep][i])a[dep+1][F(i)]=1;
		b[dep]=1;dfs(dep+1,F(mn),F(mx),cnt+1);
	}
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	rep(i,0,L-1){a[i]=tot+N;tot+=N*2;}
	int mn=N,mx=-N;
	int n=read();
	rep(i,1,n)
	{
		int x=read();
		a[0][x]=1;
		chmin(mn,x);chmax(mx,x);
	}
	ans=L;
	dfs(0,mn,mx,0);
	cout<<ans<<endl;
	for(int i=0;ans;++i)
	if(ansb[i])
	{
		--ans;
		if(ansb[i]<0)printf("-%d ",1<<i);
		else printf("%d ",1<<i);
	}
}