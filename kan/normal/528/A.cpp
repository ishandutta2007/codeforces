#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

set<int> whhor, whver;
multiset<int> szhor, szver;
int w, h, n;

char op[10];

int main()
{
	scanf("%d%d%d", &w, &h, &n);
	whhor.insert(0);
	whhor.insert(h);
	szhor.insert(h);
	whver.insert(0);
	whver.insert(w);
	szver.insert(w);
	for (int i = 0; i < n; i++)
	{
		int wh;
		scanf("%s%d", op, &wh);
		if (op[0] == 'H')
		{
			auto itnext = whhor.lower_bound(wh);
			auto itprev = prev(itnext);
			szhor.erase(szhor.find(*itnext - *itprev));
			szhor.insert(*itnext - wh);
			szhor.insert(wh - *itprev);
			whhor.insert(wh);
		} else
		{
			auto itnext = whver.lower_bound(wh);
			auto itprev = prev(itnext);
			szver.erase(szver.find(*itnext - *itprev));
			szver.insert(*itnext - wh);
			szver.insert(wh - *itprev);
			whver.insert(wh);
		}
		printf(LLD "\n", (ll)(*szhor.rbegin()) * (ll)(*szver.rbegin()));
	}
	return 0;
}