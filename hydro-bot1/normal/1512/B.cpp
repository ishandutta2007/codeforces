// Hydro submission #61aad667490967de182785f7@1638585959496
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
typedef pair<int,int> pii;
const int N = 405;
char s[N][N];
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
	int T;
	T=read();
	while(T--)
	{
		int n;
		scanf("%d",&n);
		forn(i,1,n)	
		   scanf("%s",s[i] + 1);
		int x1 = -1,y1,x2,y2;
		forn(i,1,n)	forn(j,1,n)
		{
			if(s[i][j] == '.')	continue;
			if(x1 == -1)	x1 = i,y1 = j;
			else	x2 = i,y2 = j;
		}
		
		if(x1 == x2)
		{
			if(x1 + 1 <= n)	s[x1 + 1][y1] = s[x2 + 1][y2] = '*';
			else	s[x1 - 1][y1] = s[x2 - 1][y2] = '*';
		}
		else if(y1 == y2)
		{
			if(y1 + 1 <= n)	s[x1][y1 + 1] = s[x2][y2 + 1] = '*';
			else	s[x1][y1 - 1] = s[x2][y2 - 1] = '*';
		}
		else	s[x2][y1] = s[x1][y2] = '*';
		
		forn(i,1,n)	
		   printf("%s\n",s[i] + 1);
	}
    return 0;
}
//***