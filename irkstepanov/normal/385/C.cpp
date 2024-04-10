#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <bitset>

#define pb push_back

using namespace std;

const int maxn = 1000 * 1000 * 10 + 10;
typedef long long ll;

bitset <maxn> prime;
int cnt[maxn];
ll sum[maxn];

int main()
{

    prime.set();
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }

    prime[1] = prime[0] = 0;

    for (int i = 2; i < maxn; i++)
    {
        sum[i] = sum[i - 1];
        if (prime[i])
        {
            for (int j = i; j < maxn; j += i)
            {
                sum[i] += cnt[j];
                prime[j] = 0;
            }
        }
    }

    int m;
    scanf("%d", &m);

    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l >= maxn)
        {
            printf("0\n");
            continue;
        }
        if (r >= maxn) r = maxn - 1;
        printf("%I64d\n", sum[r] - sum[l - 1]);
    }

}