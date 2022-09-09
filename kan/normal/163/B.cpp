#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
// 	#define LLD "%lld"
#endif

struct lem
{
	ll m,v,id;
};

const int maxn=100005;
const double eps=1e-9;

lem l[maxn];
ll n,k,h;
ll ans[maxn];

inline bool operator <(lem a,lem b)
{
	return (a.m<b.m)||((a.m==b.m)&&(a.v<b.v));
}

bool can(ld time)
{
	int cur=k;
	for (int i=n-1;i>=0;i--)
	{
		if ((cur*h*1.0)/l[i].v<time+eps) cur--;
		if (cur<1) return true;
	}
	return false;
}

void write(ld time)
{
	int cur=k;
	for (int i=n-1;i>=0;i--)
	{
		if ((cur*h*1.0)/l[i].v<time+eps)
		{
			ans[cur]=l[i].id;
			cur--;
		}
		if (cur<1) break;
	}
// 	cout << cur << endl;
	for (int i=1;i<=k;i++) cout << ans[i] << ' ';
	cout << endl;
}

int main()
{
	cin >> n >> k >> h;
	for (int i=0;i<n;i++) cin >> l[i].m;
	for (int i=0;i<n;i++) cin >> l[i].v;
	for (int i=0;i<n;i++) l[i].id=i+1;
	sort(l,l+n);
	ld l=0;
	ld r=1e10;
	for (int i=0;i<100;i++)
	{
		ld m=(r+l)/2;
		if (can(m)) r=m;
		else l=m;
	}
// 	cout << r << endl;
	write(r);
	return 0;
}