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

int f[1005],g[1005];

bool check(int a,int b)
{
	if (a!=b && a!=7-b) return 1;
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	int n;
	cin>>n;
	int x;
	cin>>x;
	int a,b;
	cin>>a>>b;
	if (check(a,b) && check(a,x) && check(b,x)) f[7-x]=1;
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		for (int j=1;j<=6;j++) g[j]=0;
		for (int j=1;j<=6;j++)
			for (int k=1;k<=6;k++)
			{
				if (check(a,b) && check(a,k) && check(b,k) && (j!=k))
					g[k]+=f[j];
					if (g[k]>=2) g[k]=2;
			}
		for (int j=1;j<=6;j++) f[j]=g[j];
	}
	int ans=0;
	for (int i=1;i<=6;i++) ans+=f[i];
	if (ans==1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}