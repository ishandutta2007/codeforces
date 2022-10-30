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

long long f[1000005];

vector<long long> a;

int main()
{
	#ifdef LOCAL_TEST
		freopen("b.in","r",stdin);
		freopen("b.out","w",stdout);
	#endif
	long long s,k;
	cin>>s>>k;
	f[1]=0; f[2]=1;
	int i;
	for (i=3;;i++)
	{
		for (int j=max(0ll,i-k);j<i;j++)
		{
			f[i]+=f[j];
			if (f[i]>s) break;
		}
		if (f[i]>s) break;
	}
	for (i;i>0;i--)
	{
		if (s>=f[i])
		{
			s-=f[i];
			a.push_back(f[i]);
		}
	}
	cout<<a.size()<<endl;
	cout<<a[0];
	for (int i=1;i<(int)a.size();i++) cout<<" "<<a[i];
	cout<<endl;
	return 0;
}