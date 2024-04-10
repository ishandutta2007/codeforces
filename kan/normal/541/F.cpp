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
#include <queue>

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

const int maxT = 105;

priority_queue<int> poss[maxT];
int n, T;

int main()
{
    scanf("%d%d", &n, &T);
    for (int i = 0; i < n; i++)
    {
        int t, q;
        scanf("%d%d", &t, &q);
        poss[T - t].push(q);
    }
    for (int i = T; i > 0; i--)
    {
        while (!poss[i].empty())
        {
            int a = poss[i].top();
            poss[i].pop();
            if (poss[i].empty())
            {
                poss[i - 1].push(a);
                break;
            }
            int b = poss[i].top();
            poss[i].pop();
            poss[i - 1].push(a + b);
        }
    }
    printf("%d\n", poss[0].top());
	return 0;
}