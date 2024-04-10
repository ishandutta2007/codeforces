#include <iostream>

using namespace std;
int n, k, l, c, d, p, nl, np;
int A, B, C;
int main()
{
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    A = k * l;
    B = c * d;
    C = p;
    A = A / nl;
    C = C / np;
    int a = 0;
    for (long long i = 0; i <= 1000000; i++)
    {
        if (i * n <= A && i * n <= B && i * n <= C)
            a = i;
    }
    cout << a;
}