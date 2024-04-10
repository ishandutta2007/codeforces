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

const int maxx = 60000;
const ll wh2 = ((ll)50626) * 50626;

int ans[maxx];
bool was[20];
int n;

int main()
{
    ans[0] = 0;
    for (int i = 1; i < maxx; i++)
    {
        int minb = max(0, (int)sqrt(sqrt(i)) - 5);
        int maxb = min(i - 1, (int)sqrt(i) + 5);
        for (int j = 0; j < 10; j++) was[j] = false;
        for (int j = minb; j <= maxb; j++) if (j * j <= i && ((ll)j) * j * j * j >= i) was[ans[j]] = true;
        for (int j = 0; j < 10; j++) if (!was[j])
        {
            ans[i] = j;
//             cout << i << ' ' << ans[i] << endl;
            break;
        }
    }
    scanf("%d", &n);
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        ll a;
        scanf(LLD, &a);
        if (a >= wh2) answer ^= 2;
        else if (a >= maxx) answer ^= 1;
        else answer ^= ans[a];
    }
    if (answer == 0) cout << "Rublo" << endl;
    else cout << "Furlo" << endl;
	return 0;
}