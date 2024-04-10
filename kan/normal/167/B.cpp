#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int maxn=205;

ld v[2][maxn*3][maxn];
int a[maxn],p[maxn];
int n,l,k;

int main()
{
	cin >> n >> l >> k;
	if (k>n) k=n;
	for (int i=0;i<n;i++) cin >> p[i];
	for (int i=0;i<n;i++) cin >> a[i];
	memset(v,0,sizeof(v));
	v[0][k+300][0]=1;
	for (int i=0;i<n;i++)
	{
		for (int j=-n;j<=n;j++)
		{
			for (int ll=0;ll<=n;ll++)
			{
				int knew=j+a[i];
				if (knew>n) knew=n;
				v[1][knew+300][ll+1]+=p[i]*v[0][j+300][ll]/100;
				v[1][j+300][ll]+=(100-p[i])*v[0][j+300][ll]/100;
			}
		}
		for (int j=-n;j<=n;j++)
		{
			for (int ll=0;ll<=n;ll++)
			{
				v[0][j+300][ll]=v[1][j+300][ll];
				v[1][j+300][ll]=0;
// 				cout << i << ' ' << j << ' ' << ll << ' ' << v[0][j+300][ll] << endl;;
			}
		}
	}
	ld ans=0;
	for (int j=0;j<=n;j++)
	{
		for (int ll=l;ll<=n;ll++)
		{
			ans+=v[0][j+300][ll];
		}
	}
	cout.precision(20);
	cout << ans << endl;
	return 0;
}