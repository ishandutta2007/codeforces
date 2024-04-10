#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

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
    int n = 303;
    printf("%d\n", n);
    printf("%d %d\n", 0, 1000000);
    int curx = 35005;
    int p = 302;
    for (int i = 0; i < n - 2; i++)
    {
        printf("%d %d\n", curx, p);
        curx += 2 * p;
        p--;
    }
    cerr << curx << endl;
    printf("%d %d\n", curx + 35005, 1000000);
	return 0;
}