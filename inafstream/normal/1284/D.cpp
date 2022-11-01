#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

unsigned long long val[100005],sum1[100005],sum2[100005];
unsigned long long ca[100005],cb[100005],sa1[100005],sa2[100005],sb1[100005],sb2[100005];
int n,m,i,j,la[100005],lb[100005];
struct rg
{
	int l,r,id;
}a[100005],b[100005];
bool cmp(rg x,rg y)
{
	return x.r<y.r;
}

void prework()
{
	rep(i,n)
	{
		la[i]=i;
		int l=-1,r=i-1,mid;
		while (l<r)
		{
			mid=(l+r+1)/2;
			if (a[mid].r>=a[i].l)
			{
				la[i]=mid;r=mid-1;
			}
			else l=mid;
		}
		
		lb[i]=i;
		l=-1,r=i-1,mid;
		while (l<r)
		{
			mid=(l+r+1)/2;
			if (b[mid].r>=b[i].l)
			{
				lb[i]=mid;r=mid-1;
			}
			else l=mid;
		}
	}
}

void solve()
{
	rep(i,n) val[i]=(((((((1ll*rand())<<16)+rand())<<16)+rand())<<16)+rand());
//	rep(i,n) cerr<<val[i]<<' ';cerr<<endl;
	
	rep(i,n)
	{
		sum1[i]=sum2[i]=0;sa2[i]=sb2[i]=0;
		sa1[i]=(ca[i]=val[a[i].id])+sa1[i-1];
		sb1[i]=(cb[i]=val[b[i].id])+sb1[i-1];
	}
	
	rep(i,n)
	{
		sum1[a[i].id]=sa1[i-1]-sa1[la[i]-1];
		sum2[b[i].id]=sb1[i-1]-sb1[lb[i]-1];
		sa2[la[i]]+=ca[i];sa2[i]-=ca[i];
		sb2[lb[i]]+=cb[i];sb2[i]-=cb[i];
	}
	rep(i,n)
	{
		sa2[i]+=sa2[i-1];
		sb2[i]+=sb2[i-1];
	}
	
	rep(i,n)
	{
		sum1[a[i].id]+=sa2[i];
		sum2[b[i].id]+=sb2[i];
	}
	
	rep(i,n)
	{
		if (sum1[i]!=sum2[i])
		{
			puts("NO");
			exit(0); 
		}
	}
}

int main()
{
	srand(time(NULL));
	double start=clock();
	
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%d%d%d%d",&a[i].l,&a[i].r,&b[i].l,&b[i].r);
		a[i].id=b[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	
	prework();
	
	do
	{
		solve();
	}
	while ((clock()-start)/CLOCKS_PER_SEC<1.0);
	
	puts("YES");
	return 0;
}