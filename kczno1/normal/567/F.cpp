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

template<typename T>
struct vec
{
T *a;
int n;
void clear()
{
    if (n>0) delete[] a;
    n=0;
}
void pb(const T &x)
{
    if((n&-n)==n)a=(T*)realloc(a,(n*2+1)*sizeof(T));
    /*{
        T *_a=new T [n*2];
        memcpy(_a,a,n*sizeof(T));
        a=_a;
    }*/
    a[n++]=x;
}
};
#define fore(arr) for(auto it=arr.a,end=it+arr.n;it!=end;++it)

const int N=40,T=N*2,K=105;
struct edge
{
	int type,to;//-1:= 0:< 1:> 2:<= 3:>= 
};
int n,k,t;
ll dp[T][T];
vec<edge>lk[T];
bool check(int type,int to)
{
	if(type==-1) return 0==to;
	if(type==0)  return 0<to;
	if(type==1)  return 0>to;
	if(type==2)  return 0<=to;
	             return 0>=to;
}
bool ok(int x,int y,int l,int r)
{
	fore(lk[x])
	{
		int type=it->type,to=it->to;
		if(to==x||to==y) to=0; else
		if(to<l||to>r) to=-1; else
		to=1;
		if(!check(type,to)) return 0;
	}
	fore(lk[y])
	{
		int type=it->type,to=it->to;
		if(to==x||to==y) to=0; else
		if(to<l||to>r) to=-1; else
		to=1;
		if(!check(type,to)) return 0;
	}
	return 1;
}

ll DP(int l,int r)
{
	ll &ans=dp[l][r];
	if(ans!=-1) return ans;
	
	if(l==1&&r==t) return ans=1;
	ans=0;
	if(l>1&&r<t&&ok(l-1,r+1,l,r)) ans+=DP(l-1,r+1); 
	if(l>2&&ok(l-2,l-1,l,r)) ans+=DP(l-2,r);
	if(r+2<=t&&ok(r+1,r+2,l,r)) ans+=DP(l,r+2);
	return ans;
}

int main()
{
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>k;
	int x,y;char type[5];
	rep(i,1,k)
	{
	   scanf("%d%s%d",&x,type,&y);
	   if(*type=='=') 
	   {
	   	  lk[x].pb((edge){-1,y});
	   	  lk[y].pb((edge){-1,x});
	   }
	   else
	   {
	   	   int dy=(type[1]=='=')?2:0;
	   	   if(*type=='>')dy^=1;
	   	   lk[x].pb((edge){dy,y});
	   	   lk[y].pb((edge){dy^1,x});
	   }
	}
	
	memset(dp,-1,sizeof(dp));
	ll ans=0;
	t=n*2;
	rep(i,2,t)
	if(ok(i-1,i,i,i-1))ans+=DP(i-1,i);
	cout<<ans;
}