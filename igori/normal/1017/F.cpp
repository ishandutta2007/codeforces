#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
typedef unsigned int ll;
unsigned long long int a, b, c, d, n;
unsigned long long int ans, x;
//bool prime[400000000];

//bool prime_of_6_1[50000040];
//bool prime_of_6_5[50000040];

bitset<50000016> prime_of_6_1;
bitset<50000016> prime_of_6_5;

bool prime_test(ll x)
{
    if (x == 2)
    return 1;
    if (x == 3)
    return 1;
    if (x % 6 == 1)
    {
        return prime_of_6_1[(x - 1) / 6] ^ 1;
    }
    if (x % 6 == 5)
    {
        return prime_of_6_5[(x + 1) / 6] ^ 1;
    }
    return 0;
}

unsigned long long int cnt(ll num, ll c)
{
    ll ans = 0;
    for (unsigned long long int i = num; i <= c; i = i * num)
    {
        ans = ans + c / i;
    }
    return ans;
}

int main()
{
    for (int i = 5, t = 2; i * i <= 300000000; i += t, t = 6 - t)
    {
        if (i % 6 == 1)
        {
            if (prime_of_6_1[(i - 1) / 6] == 0)
            {
                for (int j = 2; j * i <= 300000000; j++)
                {
                    if ((i * j) % 6 == 1)
                    {
                        prime_of_6_1[((i * j) - 1) / 6] = 1;
                    }
                    if ((i * j) % 6 == 5)
                    {
                        prime_of_6_5[((i * j) + 1) / 6] = 1;
                    }
                }
            }
        }
        if (i % 6 == 5)
        {
            if (prime_of_6_5[(i + 1) / 6] == 0)
            {
                for (int j = 2; j * i <= 300000000; j++)
                {
                    if ((i * j) % 6 == 1)
                    {
                        prime_of_6_1[((i * j) - 1) / 6] = 1;
                    }
                    if ((i * j) % 6 == 5)
                    {
                        prime_of_6_5[((i * j) + 1) / 6] = 1;
                    }
                }
            }
        }
    }
    cin >> n >> a >> b >> c >> d;
    for (unsigned int i = 2; i <= n; i++)
    {
        if (prime_test(i) == 1)
        {
            //cout << i << endl;
            x = cnt(i, n);
            //cout << i << " " << x << endl;
            ans = ans + x * (((i * a + b) * i + c) * i + d);
        }
    }
    cout << ans % (1LL << 32);
}