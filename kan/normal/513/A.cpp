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

int main()
{
	int n1, n2, k1, k2;
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	if (n1 > n2) printf("First\n");
	else printf("Second\n");
	return 0;
}