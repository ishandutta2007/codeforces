// Hydro submission #61aad5993db3dedd6b6f5582@1638585754025
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
#define x first
#define y second

const int N = 105;
int a[N];

int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		int n;scanf("%d",&n);
		map<int,int> st;
		forn(i,1,n)
		{
			scanf("%d",&a[i]);
			++st[a[i]];
		}
		forn(i,1,n)
		{
			if(st[a[i]] == 1)	
			{
				printf("%d\n",i);
				break;
			}
		}
	}//9
    return 0;
}