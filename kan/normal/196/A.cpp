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

const int maxn=1e5+5;

int was[maxn];

int main()
{
	string s;
	cin >> s;
	int n=s.length();
	memset(was,0,sizeof(was));
	char maxc='a';
	for (int i=n-1;i>=0;i--)
	{
		if (s[i]>maxc)
		{
			maxc=s[i];
		}
		if (s[i]==maxc) was[i]=1;
	}
	for (int i=0;i<n;i++) if (was[i]==1) printf("%c",s[i]);
	return 0;
}