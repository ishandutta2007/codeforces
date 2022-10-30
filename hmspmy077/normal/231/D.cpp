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
		freopen("d.in","r",stdin);
		freopen("d.out","w",stdout);
	#endif
	int xx,yy,zz;	cin>>xx>>yy>>zz;
	int x,y,z;	cin>>x>>y>>z;
	int a1,a2,a3,a4,a5,a6;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	int ans=0;
	if (xx>x) ans+=a6;
	if (xx<0) ans+=a5;
	if (yy>y) ans+=a2;
	if (yy<0) ans+=a1;
	if (zz>z) ans+=a4;
	if (zz<0) ans+=a3;
	cout<<ans<<endl;
	return 0;
}