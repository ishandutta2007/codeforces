#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
const int maxn = 5010;
#define pb push_back
#define rs random_shuffle
typedef long long ll;
const ll shift = 1e9;

int a, b, mod;
vector<bool> t;

inline bool bCanGet (int x)
{
	int t = mod - ((ll)x*shift)%mod;
	if (t == mod) t -= mod;
	return t <= b;
}

int main()
{	
	cin >> a >> b >> mod;
	b = min(b, mod);
	t.resize(mod+10);
	
	for (int i = 0; i <= a; i++)
	{
		if (t[i%mod])
			break;
		t[i%mod] = 1;
		if (!bCanGet(i))
		{
			printf("1 %09d", i);
			return 0;
		}
	}
	printf("2");
	return 0;
}