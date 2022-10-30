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

int a[105];

int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	int ans=0;
	for (int i=0;i<4;i++)
	{
		cin>>a[i];
		int ok=0;
		for (int j=0;j<i;j++)
			if (a[i]==a[j]) ok=1;
		ans+=ok;
	}
	cout<<ans<<endl;
	return 0;
}