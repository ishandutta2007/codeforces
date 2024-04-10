#include<bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int ch_top=1e7;
char ch[ch_top],*now_r=ch-1,*now_w=ch-1;
int read()
{
	while(*++now_r<'0');
	int x=*now_r-'0';
	while(*++now_r>='0')x=x*10+*now_r-'0';
	return x;
}
void write(int x)
{
	static char ch[20];static int top;
	do{ch[++top]='0'+x%10;}while(x/=10);
	do{*++now_w=ch[top];}while(--top);
	*++now_w='\n';
}

template <typename T> inline void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> inline void chmax(T &x,const T &y)
{
	if(x<y)x=y;
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

const int N=2e5+5;
int n,mx[N],mn[N],sz[N];
vec<int> lk[N];
void dfs(int x,bool d)
{
	int n=lk[x].n,*a=lk[x].a;
	if(!n)
	{
		mx[x]=mn[x]=sz[x]=1;
		return ;
	}
	for(int *it=a,*end=a+n;it!=end;++it)
	{
		int y=*it;
		dfs(y,d^1);
		sz[x]+=sz[y];
	}
	
	if(d==0)
	{ 
	   int ans=-N;
	   for(int i=0;i<n;++i)
	   {
	  	 int y=a[i];
	     chmax(ans,mx[y]-sz[y]);
	   }
	   mx[x]=ans+sz[x];
	}
	else 
	{
		int ans=0;
		for(int i=0;i<n;++i)
	    {
	  	  int y=a[i];
	      ans+=mx[y]-1;
	    }
	    mx[x]=ans+1;
	}
	
	if(d==1) 
	{
	   int ans=N;
	   for(int i=n-1;i>=0;--i)
	   {
			int y=a[i];
			chmin(ans,mn[y]);
	   }
	   mn[x]=ans;
	}
	else 
	{
		int ans=0;
		for(int i=n-1;i>=0;--i)
		{
			int y=a[i];
			ans+=mn[y];
		}
		mn[x]=ans;
	}
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	fread(ch,1,ch_top,stdin);
	n=read();
	for(int i=1;i<n;++i)
	{
		int x=read(),y=read();
		lk[x].pb(y);
	}
	dfs(1,0);
	cout<<mx[1]<<" "<<mn[1];
}