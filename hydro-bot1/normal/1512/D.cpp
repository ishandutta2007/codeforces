// Hydro submission #61aad6d1ef9a89de1e7604a3@1638586066540
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <limits>
#include <ios>
#include <istream>
#include <sstream>
#include <fstream>
#include <ostream>
#include <new>
#include <iosfwd>
#include <cassert>
#include <stdio.h>
#include <climits>
#include <ctime>
#include <memory>
#include <cwchar>
#include <strstream>
#include <locale>
#include <clocale>
#include <ciso646>
#include <cctype>
#include <cwctype>
#include <cerrno>
using namespace std;
typedef long long ll;
#define forn(i,x,n) for(int i = x;i <= n;++i)
#define forr(i,x,n) for(int i = n;i >= x;--i)
#define Angel_Dust ios::sync_with_stdio(0);cin.tie(0)
const int N = 2e5+7;
ll b[N];
inline int read()
{
   register int s=0,w=1;
   register char ch=getchar();
   while(ch<'0'||ch>'9')
   {
        if(ch=='-')
        {
            w=-1;
            ch=getchar();
        }
   }
   while(ch>='0'&&ch<='9')
   {
        s=s*10+ch-'0';
        ch=getchar();
   }
   return s*w;
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		int n;scanf("%d",&n);
		ll sum = 0;
		map<ll,int> st;
		forn(i,1,n + 2)	scanf("%lld",&b[i]),sum += b[i],++st[b[i]];
		
		bool ok = 0;
		ll x = -1;
		forn(i,1,n + 2)
		{
			if((sum - b[i]) % 2)	continue;
			--st[b[i]];
			if(st.count((sum - b[i]) / 2) && st[(sum - b[i]) / 2])
			{
				ok = 1;
				x = b[i];
				break;
			}
			++st[b[i]];
		}
		if(!ok)	puts("-1");
		else
		{
			bool xflag = 0,sflag = 0;
			forn(i,1,n + 2)
			{
				if(b[i] == x && !xflag)
				{
					xflag = 1;
					continue;
				}
				else if(b[i] == (sum - x) / 2 && !sflag)
				{
					sflag = 1;
					continue;
				}
				printf("%lld ",b[i]);
			}
			puts("");
		}
	}
    return 0;
}//****99