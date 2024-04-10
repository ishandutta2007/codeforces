#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
void chmin(int &x,int y)
{
    if (x>y) x=y;
}
const int  N = 1000100;
const int oo = N-1; 

int f[N],c[N][2],v[N],mx[N],sz[N],xu[N];
bool rev[N];

#define get(x) (x==c[f[x]][1])
#define root(x) (x!=c[f[x]][0]&&x!=c[f[x]][1])
void sc(int fa,int x,bool d)
{
    f[x]=fa;c[fa][d]=x;
}
void upd(int x)
{
	if(!x)return ;
	sz[x]=sz[c[x][0]]+sz[c[x][1]]+xu[x];
    int l=mx[c[x][0]],r=mx[c[x][1]];
    if (v[x]>v[l]) mx[x]=v[x]>v[r]?x:r;
    else mx[x]=v[l]>v[r]?l:r;
}
void pushdown(int x)
{
    if (!rev[x]) return;
   int l=c[x][0],r=c[x][1];
   c[x][1]=l;c[x][0]=r;
   rev[x]=0;rev[l]^=1;rev[r]^=1;	
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
        splay(x);
		xu[x]+=sz[c[x][1]]-sz[y];
		c[x][1]=y;
		upd(x);
        y=x;x=f[x];
    }while (x); 
} 
void toroot(int x)
{
    access(x);splay(x);
}
void chroot(int x)
{
    toroot(x);rev[x]=1;
}

void merge(int x,int y)
{
    chroot(x);access(y);
    f[x]=y;xu[y]+=sz[x];
    upd(y);
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
    return f[x]?mx[y]:oo;
}

struct edge
{
    int x,y,t;
}l[N];

int main()
{
#ifdef kcz
    freopen("1.in","r",stdin);
#endif
	int n,q,k,i;
	cin>>n>>q>>k;
	
    for (i=1;i<=n;++i) {mx[i]=i;sz[i]=xu[i]=1;}
	int t=1,head=n+1,tail=n;
	rep(tmp,1,q)
    {
		//cerr<<tmp<<endl;
		int ty;
		scanf("%d",&ty);
		if(ty==3){++t;continue;}
		int x;
		scanf("%d",&x);
		if(ty==2)
		{
			for(;head<=tail&&l[head].t<=t-k;++head)
			{
        		int p=qiu(l[head].x,l[head].y);
        		if (p==head)
                {
        			 cut(p,l[p].x);cut(p,l[p].y);
                }
			}
			//printf("%d %d %d %d %d\n",x,f[x],c[x][0],c[x][1],xu[x]);
			//printf("%d\n",sz[x]);
			toroot(x);
    //        upd(8);
//			printf("%d %d %d %d %d\n",f[8],sz[8],c[8][0],c[8][1],sz[3]);
            //rep(y,1,n)
            //if(f[y]==x)
			    //printf("%d %d %d %d %d %d\n",y,f[y],c[y][0],c[y][1],xu[y],sz[y]);
			//printf("%d %d %d %d %d\n",x,f[x],c[x][0],c[x][1],xu[x]);
			printf("%d\n",sz[x]);
			continue;
		}
		int y;
		scanf("%d",&y);
		l[++tail]={x,y,t};
        		int p=qiu(x,y);
        		if (p!=oo)
        		{
                   // cerr<<p<<" "<<l[p].x<<" "<<l[p].y<<endl;
        			 cut(p,l[p].x);cut(p,l[p].y);
        		}
        v[tail]=oo-t;mx[tail]=tail;
        merge(tail,x);merge(tail,y);
//        printf("%d %d %d\n",tail,x,y);
    }
}