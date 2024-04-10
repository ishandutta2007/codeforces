#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int sqrt (int x)
{
    return floor(sqrt((double)x));
};


bool isPrime (int x)
{
    for (int i = 2; i < sqrt(x) + 1; i++)
        if (x % i == 0)
            return 0;
    return 1;
};

vector<int> primes;

bool isAlmost (int x)
{
    int div1 = 0, div2 = 0;
    int i = 0;
    while (x != 1)
    {
        if (x % primes[i] == 0)
            if (div1 == 0)
            {
                div1 = primes[i];
                while (x % primes[i] == 0)
                    x /= primes[i];
            }
            else if (div2 == 0)
            {
                div2 = primes[i];
                while (x % primes[i] == 0)
                    x /= primes[i];
            }
            else
                return 0;
        i++;
    }
    return div1 && div2;
};

int main()
{
    for (int i = 2; i < 3000; i++)
        if (isPrime(i))
        {
            primes.push_back(i);
        }

    int n, sum = 0;
    cin >> n;
    for (int i = 6; i <= n; i++)
    {
        sum += isAlmost(i);
    }
    cout << sum;
    return 0;
}