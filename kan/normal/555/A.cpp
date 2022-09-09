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

int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    int answer = k - 1;
    for (int i = 0; i < k; i++)
    {
        int t, last;
        scanf("%d", &t);
        scanf("%d", &last);
        bool found = (last != 1);
        for (int j = 0; j < t - 1; j++)
        {
            int cur;
            scanf("%d", &cur);
            if (found || cur != last + 1)
            {
                found = true;
                answer += 2;
            }
            last = cur;
        }
    }
    printf("%d\n", answer);
	return 0;
}