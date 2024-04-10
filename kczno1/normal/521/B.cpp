#include<bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int ch_top=1e7;
char ch[ch_top],*now_r=ch-1,*now_w=ch-1;
int read()
{
	while(*++now_r<'-');
	if(*now_r=='-')
	{
		int x=*++now_r-'0';
	    while(*++now_r>='0')x=x*10+*now_r-'0';
	    return -x;
	}
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

const int N=1e5+5,U=1e9+2,D=1e9+9;
int n,d;
bool have[N],a[N*3];
int px[N];vec<int>lk[N];

void modify(int i,bool b)
{
	i+=d;
	if(a[i]==b) return ;
	a[i]=b;
	while(i>>=1)a[i]=a[i*2]||a[i*2+1];
}
int get_mx()
{
	int i=1;
	while(i<=d)
	if(a[i*2+1])i=i*2+1;
	else i*=2;
	return i-d;
}
int get_mn()
{
	int i=1;
	while(i<=d)
	if(a[i*2])i*=2;
	else i=i*2+1;
	return i-d;
}

bool b[N];
struct que
{
	int a[3],n;
	void pb(int x)
    {
    	a[n++]=x;
    }
    bool check()
    {
    	bool num=0;
    	for(int i=0;i<n;++i)
    	if(have[a[i]]==0) 
    	{
    		if(num) return 1;
    		num=1;
    	}
    	return 0;
    }
    bool ok()
    {
    	rep(i,0,n-1)
    	if(b[a[i]]==0&&have[a[i]]==0) return 0;
    	return 1;
    }
}fa[N],son[N];

bool x_xiao(int x,int y)
{
	return px[x]<px[y];
}

void sc(int f,int x)
{
	fa[x].pb(f);son[f].pb(x);
}
void check(vec<int> &a1,vec<int> &a2)
{
	int h2=0;
	rep(h1,0,a1.n-1)
	{
		int x=a1.a[h1];
		while(h2<a2.n&&px[a2.a[h2]]<px[x]-1) ++h2;
		for(int j=0;j<3;++j)
		if(h2+j<a2.n)
		if(px[a2.a[h2+j]]<=px[x]+1) sc(x,a2.a[h2+j]);
	}
}

ll ans;
int q[20],top;
void make(int i)
{
	ans=(ans*n+i-1)%D;
//cout<<i<<endl;
	have[i]=1;
	modify(i,0);
	top=0;
	for(int j=0;j<fa[i].n;++j)
	{
	   int f=fa[i].a[j];
	   if(have[f]==0)
	   if(b[f]!=son[f].check())
	   {
	   	   b[f]^=1;
	   	   for(int j2=0;j2<son[f].n;++j2)
	   	   	   q[++top]=son[f].a[j2];
	   }
	}
	for(int i=1;i<=top;++i)
	{
		int x=q[i];
		if(have[x]==0) modify(x,fa[x].ok());
	}
	for(int j=0;j<son[i].n;++j)
	{
		int x=son[i].a[j];
	  if(have[x]==0)modify(x,fa[x].ok());
	}
}

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	fread(ch,1,ch_top,stdin);
	n=read();
	for(d=1;d<n;d*=2);d-=1;
	rep(i,1,n) 
    {
	   px[i]=read();
	   lk[read()].pb(i);
	}	
	for(int y=0;y<n;++y) sort(lk[y].a,lk[y].a+lk[y].n,x_xiao);
	for(int y=1;y<n;++y) check(lk[y],lk[y-1]);
	rep(i,1,n) b[i]=son[i].check();
	rep(i,1,n) modify(i,fa[i].ok());
	
	ans=0;
	rep(i,1,n) 
	if((i&1)==1) make(get_mx());
	else make(get_mn());
	cout<<ans;
}