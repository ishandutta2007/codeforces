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

int a[1005][1005];

int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	int m;
	cin>>m;
	int tmp=0;
	int i=100;
	while (i*(i-1)*(i-2)/6>m) i--;
	m-=i*(i-1)*(i-2)/6;
	for (int j=0;j<i;j++)
		for (int k=0;k<i;k++)
			if (j!=k) a[j][k]=1;
	tmp+=i;
	while (m)
	{
		int p=i;
		while (p*(p-1)/2>m) p--;
		for (int j=0;j<p;j++) a[j][tmp]=a[tmp][j]=1;
		tmp++;
		m-=p*(p-1)/2;
	}
	cout<<tmp<<endl;
	for (int i=0;i<tmp;i++)
	{
		for (int j=0;j<tmp;j++) cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}