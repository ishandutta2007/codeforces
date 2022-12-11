#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=1000005,MOD=1000000007;

struct md
{
	int l,r,c;
};

int k,a[MAXN],l[MAXN],r[MAXN];

void get_mod(int len,vector <md> &ret)
{
	ret.clear();
	if (len%k==0)
		ret.pb({0,k-1,len/k});
	else
	{
		ret.pb({0,(len-1)%k,len/k+1});
		ret.pb({(len-1)%k+1,k-1,len/k});
	}
}

int cal(const md &a,const md &b)
{
	int ret=0;
	// if (0>=b.l&&a.l<=1&&1<=a.r)
	// 	ret++;
	// if (b.l<=1&&1<=b.r&&0>=a.l)
	// 	ret++;
	int l=k-b.r,r=k-b.l;
	l=max(l,a.l);
	r=min(r,a.r);
	if (r>=l)
		ret=r-l+1;
	if (a.l==0&&b.l==0)
		ret++;
	return (LL)ret*a.c%MOD*b.c%MOD;
}

int main()
{
	//freopen("read.txt","r",stdin);
	int n;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		int &j=l[i];
		for (j=i-1;j&&a[j]<=a[i];j=l[j]);
	}
	for (int i=n;i>=1;i--)
	{
		int &j=r[i];
		for (j=i+1;j<=n&&a[j]<a[i];j=r[j]);
	}
	int ans=0;
	if (k==2)
	{
		for (int i=1;i<=n;i++)
			ans=(ans+((LL)(i-l[i])*(r[i]-i)-1)%MOD*a[i])%MOD;
	}
	else
	{
		k--;
		vector <md> lf,rg;
		for (int i=1;i<=n;i++)
		{
			get_mod(i-l[i],lf);
			get_mod(r[i]-i,rg);
			int t=0;
			for (auto &a:lf)
				for (auto &b:rg)
					t=(t+cal(a,b))%MOD;
			t--;
			ans=(ans+(LL)t*a[i])%MOD;
		}
	}
	printf("%d",ans);
	return 0;
}