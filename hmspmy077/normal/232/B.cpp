#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

const long long mo=1000000007;

long long f[105][100*100+5],c[105][105],a[105];

long long cal(long long i,long long j)
{
	if (j==1) return i;
	if (j%2==1) return cal(i,j-1)*i%mo;
	long long k=cal(i,j/2);
	return k*k%mo;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("b.in","r",stdin);
		freopen("b.out","w",stdout);
	#endif
	long long n,m,q;
	cin>>n>>m>>q;
	f[0][0]=1;
	for (int i=0;i<=n;i++) c[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=n;j++) a[j]=cal(c[n][j],m/n+(m%n>=i));
		for (int j=0;j<=(i-1)*n && j<=q;j++)
			for (int k=0;k<=n;k++)
			{
				if (j+k>q) break;
				(f[i][j+k]+=f[i-1][j]*a[k])%=mo;
			}
	}
	cout<<f[n][q]<<endl;
	return 0;
}