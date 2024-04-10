#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

int main()
{
	int x;
	scanf("%d",&x);
	if (x==3)
	{
		cout << 5 << endl;
		return 0;
	}
	for (int sz=1;;sz++)
	{
		if (x%4==0 && sz%2==0)
		{
			int maxx=((sz/2-1)*(sz/2-1)+1)/2;
			if (maxx>=x)
			{
				cout << sz << endl;
				return 0;
			}
		}
		if (sz%2==1)
		{
			int maxx=1+(sz/2/2)*4+(((sz/2)*(sz/2)+1)/2)*4;
			if (x<=maxx)
			{
				cout << sz << endl;
				return 0;
			}
		}
	}
	return 0;
}