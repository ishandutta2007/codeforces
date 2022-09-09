#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

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
	int n;
	ld a,d;
	cin >> n >> a >> d;
	ld last=0;
	for (int i=0;i<n;i++)
	{
		ld t,v;
		cin >> t >> v;
		ld s=v*v/2/a;
		if (s>d)
		{
// 			cout << "was" << endl;
			t=t+sqrt(2*d/a);
		} else
		{
			t=t+v/a+(d-s)/v;
		}
		last=max(last,t);
		printf("%.6f\n",(double)last);
	}
	return 0;
}