#include<cstdio>
#include<algorithm>

long long a[300001];
long long d[300001];

struct tree
{
	int s;
	int e;
	int l;
	int r;
	long long y;
	long long z;
	long long max;
} T[1111111];
int Tn;

int init(int s,int e)
{
	int i=Tn++;
	T[i].s=s;
	T[i].e=e;
	if(s<e)
	{
		T[i].l=init(s,(s+e)/2);
		T[i].r=init((s+e)/2+1,e);
	}
	return i;
}

void update(int i,int x,long long y,long long z)
{
    if(x<T[i].s||x>T[i].e)return;
    if(x==T[i].s&&x==T[i].e)
	{
		T[i].y=y;
		T[i].z=z;
		T[i].max=-9e18;
	}
    else
	{
		update(T[i].l,x,y,z);
		update(T[i].r,x,y,z);
		T[i].y=std::max(T[T[i].l].y,T[T[i].r].y);
		T[i].z=std::max(T[T[i].l].z,T[T[i].r].z);
		T[i].max=std::max(T[T[i].l].max,T[T[i].r].max);
		T[i].max=std::max(T[i].max,T[T[i].l].y+T[T[i].r].z);
	}
}

std::pair<std::pair<long long,long long>,long long> get(int i,int s,int e)
{
    if(s<T[i].s)s=T[i].s;
    if(e>T[i].e)e=T[i].e;
    if(s>e)return std::make_pair(std::make_pair((long long)-4e18,(long long)-4e18),(long long)-9e18);
    if(s==T[i].s&&e==T[i].e)return std::make_pair(std::make_pair(T[i].y,T[i].z),T[i].max);
    std::pair<std::pair<long long,long long>,long long> P,Q;
    P=get(T[i].l,s,e);
    Q=get(T[i].r,s,e);
    return std::make_pair(std::make_pair(std::max(P.first.first,Q.first.first),std::max(P.first.second,Q.first.second)),std::max(P.first.first+Q.first.second,std::max(P.second,Q.second)));
}

int main()
{
	int i,j,n,m;
	scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
	{
		scanf("%I64d",&d[i]);
		d[i]+=d[i-1];
	}
	for(i=n+1;i<=2*n;i++)d[i]=d[i-n]+d[n];
	for(i=0;i<n;i++)scanf("%I64d",&a[i]);
    for(i=n;i<=2*n;i++)a[i]=a[i-n];
	init(0,2*n);
    for(i=0;i<=2*n;i++)update(0,i,2*a[i]-d[i],2*a[i]+d[i]);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		i--;j--;
        if(i>j)printf("%I64d\n",get(0,j+1,i-1).second);
        else printf("%I64d\n",get(0,j+1,i+n-1).second);
	}
}