#include <iostream>
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
// 	#define LLD "%lld"
#endif

const int maxn=300005;

ll n,l,v1,v2;
ll a[maxn];
ld ans[maxn];

int main()
{
	cin >> n >> l >> v1 >> v2;
	for (int i=0;i<n;i++) cin >> a[i];
	for (int i=0;i<n;i++) a[n+i]=a[i]+2*l;
	for (int i=0;i<n;i++) a[2*n+i]=a[i]+4*l;
	ld x=l*(1-1.0*v1/(v1+v2));
	ld curl=0;
	int currid=0;
	while (a[currid]<x) currid++;
	int curlid=0;
	ld curr=x;
	while (curl<2*l)
	{
		ld next=min(a[currid]-curr,a[curlid]-curl);
		if (next+curl>2*l) next=2*l-curl;
		ans[currid-curlid]+=(next)/(2*l);
		if (a[currid]-curr<a[curlid]-curl)
		{
			curr=a[currid];
			curl=curr-x;
			currid++;
		} else
		{
			curl=a[curlid];
			curr=curl+x;
			curlid++;
		}
	}
	cout.precision(20);
	for (int i=0;i<=n;i++) cout << ans[i] << endl;
	return 0;
}