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

inline int tri(int sz)
{
    return sz * sz;
}

inline int rect(int s1, int s2)
{
    return 2 * s1 * s2;
}

int main()
{
    int a0, a1, a2, a3, a4, a5;
    scanf("%d%d%d%d%d%d", &a0, &a1, &a2, &a3, &a4, &a5);
    if (a1 < a5)
    {
        swap(a1, a5);
        swap(a2, a4);
    }
    cout << tri(a5) + tri(a2) + rect(a0, a5) + rect(a3, a2) + rect(a1 - a5, a0 + a5) << endl;
	return 0;
}