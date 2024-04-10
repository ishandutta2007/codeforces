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

long long a[65][65];
long long l[1005][65][65];
int ed,m;

int cal(char c)
{
	if (c>='a' && c<='z') return c-'a';
	return c-'A'+26;
}

void work(long long n)
{
	if (n==1)
	{
		ed++;
		for (int i=0;i<m;i++)
			for (int j=0;j<m;j++) l[ed][i][j]=a[i][j];
		return;
	}
	if (n%2==1)
	{
		work(n-1);
		ed++;
		for (int i=0;i<m;i++)
			for (int j=0;j<m;j++)
				for (int k=0;k<m;k++)
					(l[ed][i][j]+=l[ed-1][i][k]*a[k][j])%=mo;
		return;
	}
	work(n/2);

		ed++;
		for (int i=0;i<m;i++)
			for (int j=0;j<m;j++)
				for (int k=0;k<m;k++)
					(l[ed][i][j]+=l[ed-1][i][k]*l[ed-1][k][j])%=mo;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("e.in","r",stdin);
		freopen("e.out","w",stdout);
	#endif
	long long n; cin>>n;
	int q;
	cin>>m>>q;
	if (n==1) cout<<m<<endl;
	else
	{
		for (int i=0;i<m;i++)
			for (int j=0;j<m;j++) a[i][j]=1;
		while (q--)
		{
			char x,y;
			cin>>x>>y;
			a[cal(x)][cal(y)]=0;
		}
		long long ans=0;
		if (n==2)
		{
			for (int i=0;i<m;i++)
				for (int j=0;j<m;j++) ans+=a[i][j];
			cout<<ans<<endl;
		}
		else
		{
			work(n-1);
			for (int i=0;i<m;i++)
				for (int j=0;j<m;j++)
					(ans+=l[ed][i][j])%=mo;
			cout<<ans<<endl;
		}
	}
	return 0;
}