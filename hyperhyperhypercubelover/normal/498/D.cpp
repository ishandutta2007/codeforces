#include<cstdio>

int a[100000];
struct tree
{
    int s;
    int e;
    int l;
    int r;
    int d[60];
} T[222222];
int Tn;

void init(int x,int s,int e)
{
    T[x].s=s;
    T[x].e=e;
    if(s<e)
	{
		T[x].l=++Tn;
		T[x].r=++Tn;
        init(T[x].l,s,(s+e)/2);
        init(T[x].r,(s+e)/2+1,e);
		int i;
		for(i=0;i<60;i++)T[x].d[i]=T[T[x].l].d[i]+T[T[x].r].d[(i+T[T[x].l].d[i])%60];
	}
	else
	{
		int i;
		for(i=0;i<60;i++)T[x].d[i]=(i%a[s]==0)+1;
	}
}

int calc(int x,int s,int e,int t)
{
	int r=0;
	if(s<T[x].s)s=T[x].s;
    if(e>T[x].e)e=T[x].e;
    if(s>e)return 0;
    if(s==T[x].s&&e==T[x].e)return T[x].d[t%60];
    r=calc(T[x].l,s,e,t);
	return r+calc(T[x].r,s,e,t+r);
}

void update(int x,int y,int t)
{
	if(T[x].s>y||T[x].e<y)return;
    if(T[x].s==y&&T[x].e==y)
	{
		int i;
		for(i=0;i<60;i++)T[x].d[i]=(i%t==0)+1;
		return;
	}
	update(T[x].l,y,t);
	update(T[x].r,y,t);
	int i;
	for(i=0;i<60;i++)T[x].d[i]=T[T[x].l].d[i]+T[T[x].r].d[(i+T[T[x].l].d[i])%60];
}

char s[4];

int main()
{
	int i,n,m,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
    init(0,0,n-1);
    scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%s%d%d",s,&j,&k);
		if(s[0]=='A')printf("%d\n",calc(0,j-1,k-2,0));
		else update(0,j-1,k);
	}
}