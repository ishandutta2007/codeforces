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



int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	int n; cin>>n;
	int ans=0;
	while (n--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if (a+b+c>=2) ans++;
	}
	cout<<ans<<endl;
	return 0;
}