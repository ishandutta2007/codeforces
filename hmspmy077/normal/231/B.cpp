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

int a[1005];

int main()
{
	#ifdef LOCAL_TEST
		freopen("b.in","r",stdin);
		freopen("b.out","w",stdout);
	#endif
	int n,d,l;
	cin>>n>>d>>l;
	int tmp=0;
	for (int i=0;i<n;i++)
	{
		a[i]=1;
		if (i%2==0) tmp++;
		else tmp--;
	}
	for (int i=0;i<n;i++)
	{
		while (i%2==0 && a[i]<l && tmp<d) a[i]++,tmp++;
		while (i%2!=0 && a[i]<l && tmp>d) a[i]++,tmp--;
	}
	if (tmp!=d) cout<<-1;
	else for (int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}