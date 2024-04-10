//# pragma GCC optimize ("O2")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

template <typename T> inline void chmin(T &x,const T &y)
{
    if(x>y)x=y;
}
template <typename T> inline void chmax(T &x,const T &y)
{
    if(x<y)x=y;
}

#define gc (c=getchar())
int read()
{
	char c;
    while(gc<'-');
    int x=c-'0';
    while(gc>='0')x=x*10+c-'0';
    return x;
}

template<typename T>
struct vec
{
T *a;
int n;
void push_back(const T &x)
{
    if((n&-n)==n)//a=(T*)realloc(a,(n*2+1)*sizeof(T));
    {
        T *_a=new T [n*2+1];
        memcpy(_a,a,n*sizeof(T));
        a=_a;
    }
    a[n++]=x;
}
};

const int N=2500+5;
int n,m;

ll w;
struct BIT
{
ll c[N][N];
void add(int x,int y)
{
	for(int i=x;i<=n;i+=i&-i)
	for(int j=y;j<=m;j+=j&-j)
	 c[i][j]^=w;
}
ll qiu(int x,int y)
{
	ll ans=0;
	for(int i=x;i;i-=i&-i)
	for(int j=y;j;j-=j&-j)
	 ans^=c[i][j];
	return ans;
}
}c;

int main()
{
    //freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
    int q;
    cin>>n>>m>>q;
    while(q--)
    {
    	int t=read(),x1=read(),y1=read(),x2=read(),y2=read();
    	if(t==3)
    	{
    		if(c.qiu(x1,y1)==c.qiu(x2,y2)) puts("Yes");
    		else puts("No");
    	}
    	else
    	{
    		w=(ll(x1*N+y1)*N+x2)*N+y2;
    		c.add(x1,y1);c.add(x2+1,y2+1);
    		c.add(x1,y2+1);c.add(x2+1,y1);
    	}
    }
}