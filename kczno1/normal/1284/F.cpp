#include<bits/stdc++.h>
using namespace std;

void chmin(int &x,int y)
{
    if (x>y) x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
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
#define N 900100 
#define oo 300000 

int f[N],c[N][2],v[N],mxl[N],mxr[N];
bool rev[N];

#define get(x) (x==c[f[x]][1])
#define root(x) (x!=c[f[x]][0]&&x!=c[f[x]][1])
void sc(int fa,int x,bool d)
{
    f[x]=fa;c[fa][d]=x;
}
void rever(int x)
{
	rev[x]^=1;swap(mxl[x],mxr[x]);
}
void pushdown(int x)
{
    if (!rev[x]) return;
   int l=c[x][0],r=c[x][1];
   c[x][1]=l;c[x][0]=r;
   rev[x]=0;rever(l);rever(r);	
}
void upd(int x)
{
	pushdown(x);
    int l=mxr[c[x][0]],r=mxr[c[x][1]];
    if (v[x]>=v[l]) mxr[x]=v[x]>v[r]?x:r;
    else mxr[x]=v[l]>v[r]?l:r;
    
    l=mxl[c[x][0]];r=mxl[c[x][1]];
    if (v[x]>v[l]) mxl[x]=v[x]>=v[r]?x:r;
    else mxl[x]=v[l]>=v[r]?l:r;
}

void rot(int x)
{
    int fa=f[x];bool d=get(x);
    if (root(fa)) f[x]=f[fa];
    else sc(f[fa],x,get(fa));
    sc(fa,c[x][!d],d);sc(x,fa,!d);
    upd(fa);
}

int st[N],top;
void splay(int x)
{
    int fa;
    st[top=1]=x;
    for (fa=x;!root(fa);) st[++top]=fa=f[fa];
    do
    {
        pushdown(st[top]);
    }while (--top);
    
    for (;!root(x);)
    {
        fa=f[x]; 
        if (root(fa)) {rot(x);break;}
        rot(get(fa)==get(x)?fa:x);rot(x);
    }
    upd(x);
}

void access(int x)
{
    int y=0;
    do
    {
        splay(x);c[x][1]=y;upd(x);
        y=x;x=f[x];
    }while (x); 
} 
void toroot(int x)
{
    access(x);splay(x);
}
void chroot(int x)
{
    toroot(x);rever(x);
}

void merge(int x,int y)
{
    chroot(x);access(y);
    f[x]=y;
}

void cut(int x,int y)
{
    chroot(x);toroot(y);
    f[x]=c[y][0]=0;
    upd(y);
}

int qiu(int x,int y)
{
    chroot(x);toroot(y);
    return f[x]?mxr[y]:oo;
}
void print(int x)
{
	if(!x)return ;
	pushdown(x);
	print(c[x][0]);
	printf("%d %d\n",x,v[x]);
	print(c[x][1]);
}

struct edge
{
    int x,y,a,b;
    bool operator <(const edge&i)const
    {
        return a<i.a;
    }
}l[N];int t;
vector<int>lk[N];
void dfs(int x,int fr)
{
	for(auto y:lk[x])
	if(y!=fr)
	{
		dfs(y,x);
		int j=qiu(x,y);
		/*print(y);
		cout<<mxr[y];
		exit(0);*/
        
    	cut(j,l[j].x);cut(j,l[j].y);
    	
    	printf("%d %d %d %d\n",x,y,l[j].x,l[j].y);
        
        ++t;
        l[t].x=x;l[t].y=y;v[t]=1;
        merge(t,x);merge(t,y);
	}
}

int main()
{
#ifdef kcz
    freopen("1.in","r",stdin);
#endif
    int n;
    cin>>n;
    t=n;
    rep(i,1,n-1){int x=read(),y=read();lk[x].push_back(y);lk[y].push_back(x);}
    rep(i,1,n-1)
    {
    	++t;v[t]=2;
    	l[t].x=read();l[t].y=read();
        merge(t,l[t].x);merge(t,l[t].y);
       // if(t==5)
	//	{
	//		cerr<<l[t].x<<" "<<l[t].y<<endl;
			
	//	}
    } 
 /*  qiu(3,4);
	print(4);
	cout<<mx[4];
	exit(0);*/
    
    printf("%d\n",n-1); 
    dfs(1,0);
}