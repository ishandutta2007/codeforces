#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long n, k;
long long a[2000];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > k * 2)
        {
            ans++;
            i--;
            k *= 2;
        }
        if (i >= 0)
            k = max(a[i], k);
    }
    cout << ans;
}