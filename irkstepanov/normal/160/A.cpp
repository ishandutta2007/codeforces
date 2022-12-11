#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    int n;
    int a[120];
    int sum1 = 0, sum2 = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum2 += a[i];
    }

    sort (a, a + n);
    for (int i = n - 1; i >= 0; i--)
    {
        sum1 += a[i];
        sum2 -= a[i];
        if (sum1 > sum2) {cout << n - i; return 0;}
    }

}