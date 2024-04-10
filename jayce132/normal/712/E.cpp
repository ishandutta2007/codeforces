#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)a.size())
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}

const int maxn=1e5+20;

struct matrix {
	double a[2][2];
	double* operator [](int index){ return a[index];}
	matrix(int op=0){ memset(a,0,sizeof(a)); REP(i,0,1)a[i][i]=op;}
};

double gl[maxn];

inline matrix operator *(matrix a,matrix b)
{
	matrix c;
	REP(i,0,1)REP(j,0,1)REP(k,0,1)c[i][j]+=a[i][k]*b[k][j];
	return c;
}

struct node {
	matrix s;
	void Merge(node L,node R) {
		s=L.s*R.s;
	}
};
node c[(1<<18)+20];
#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

inline matrix MAKE(double x)
{
	matrix A;
	A[1][0]=1;
	A[1][1]=1/x;
	A[0][1]=-(1-x)/x;
	return A;
}

void make_tree(int o,int l,int r)
{
	if(l==r)return c[o].s=MAKE(gl[l]),void();
	int mid=l+r>>1;
	make_tree(left);
	make_tree(right);
	c[o].Merge(c[lc],c[rc]);
}


void update(int x,int o,int l,int r)
{
	if(l==r)return c[o].s=MAKE(gl[l]),void();
	int mid=l+r>>1;
	if(x<=mid)update(x,left);
	else update(x,right);
	c[o].Merge(c[lc],c[rc]);
}

int n,q;

inline void init()
{
	n=read();q=read();
	REP(i,1,n)
	{
		int a=read(),b=read();
		gl[i]=1.*a/b;
	}
	make_tree(1,1,n);
}

matrix query(int ql,int qr,int o,int l,int r)
{
	if(ql<=l && r<=qr)return c[o].s;
	int mid=l+r>>1;
	if(qr<=mid)return query(ql,qr,left);
	else if(ql>mid)return query(ql,qr,right);
	else return query(ql,qr,left)*query(ql,qr,right);
}

inline void doing()
{
	REP(i,1,q)
	{
		int op=read();
		if(op==1)
		{
			int id=read(),a=read(),b=read();
			gl[id]=1.0*a/b;
			update(id,1,1,n);
		}else
		{
			int l=read(),r=read();
			matrix t;
			t=query(l,r,1,1,n);
			double s=t[1][1];
			if(isnan(s))puts("0");
			else printf("%.10lf\n",1/s);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("712e.in","r",stdin);
    freopen("712e.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}