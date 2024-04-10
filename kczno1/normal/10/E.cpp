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

const int N=400+5,inf=2e9;
int n,c[N];
int ans=inf;
int G(int x)
{
	int ans=0;
	rep(i,1,n)
	{
		int d=x/c[i];
		ans+=d;
		x-=c[i]*d;
	}
	return ans;
}

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	n=read();
	rep(i,1,n)c[i]=read();
	rep(i,2,n)
	{
		int x=c[i-1]-1;
		int x0=x;
		int m=0;
		rep(j,i,n)
		{
			int d=x/c[j];
			m+=d;
			x-=c[j]*d;
			if(m+1<G(x0-x+c[j]))
				chmin(ans,x0-x+c[j]);
		}
	}
	if(ans==inf)puts("-1");
	else cout<<ans<<endl;
}