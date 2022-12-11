#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

int n,p[MAXN];
bool f[MAXN];

int solve(int a,int b,int h,int w)
{
	int m1=(a-1)/h+1,m2=(b-1)/w+1;
	if (m1==1&&m2==1) return 0;
	LL pi=1,_min=LLONG_MAX;
	memset(f,0,sizeof(f));
	f[1]=true;
	if (m1==1) _min=1;
	for (int i=0;i<n;i++)
	{
		pi*=p[i];
		for (int j=1;j<=100000;j++)
			if (f[j]&&(LL)j*p[i]>=m1)
				_min=min(_min,(LL)j*p[i]);
		if (pi/_min>=m2)
			return i+1;
		for (int j=100000;j>=1;j--)
			if (j%p[i]==0&&f[j/p[i]])
				f[j]=true;
	}
	return -1;
}

int main()
{
	int a,b,h,w;
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
	for (int i=0;i<n;i++)
		scanf("%d",&p[i]);
	sort(p,p+n,greater <int> ());
	int ret1=solve(a,b,h,w),ret2=solve(b,a,h,w);
	if (ret1==-1)
		printf("%d",ret2);
	else if (ret2==-1)
		printf("%d",ret1);
	else
		printf("%d",min(ret1,ret2));
	return 0;
}