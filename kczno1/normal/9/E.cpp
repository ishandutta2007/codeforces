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

const int N=50+5;
int fa[N],du[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
pii ans[N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","r",stdin);
	int n=read(),m=read();
	rep(i,1,n)fa[i]=i;
	rep(i,1,m)
	{
		int x=read(),y=read();
		++du[x];++du[y];
		fa[find(x)]=find(y);
	}
	rep(i,1,n)
	if(du[i]>2)
	{
		puts("NO");
		return 0;
	}
	int top=0;
	rep(i,1,n)
	rep(j,i,n)
	if(find(i)!=find(j)&&du[i]<2&&du[j]<2)
	{
		ans[++top]=mp(i,j);
		++du[i];++du[j];
		fa[find(i)]=find(j);
	}
	if(m+top==n-1)	
	{	
		++top;
		rep(i,1,n)
		while(du[i]<2)
		{
			++du[i];
			if(!ans[top].first)ans[top].first=i;
			else ans[top].second=i;
		}
	}
	rep(i,1,n)
	if(find(i)!=find(1))
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n",top);
	rep(i,1,top)printf("%d %d\n",ans[i].first,ans[i].second);
}