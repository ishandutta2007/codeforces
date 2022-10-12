#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n;
int a[10000];
int ans = 12000, count_of_ones;

int gsd(int a, int b)
{
    return b > 0 ? gsd(b, a % b) : a;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            count_of_ones++;
    }
    for (int i = 0; i < n; i++)
    {
        int k = a[i];
        for (int j = i + 1; j < n; j++)
        {
            k = gsd(k, a[j]);
            if (k == 1)
            {
                //cout << i << " " << j << endl;
                if (j - i < ans)
                    ans = j - i;
                break;
            }
        }
    }
    if (count_of_ones == n)
    {
        cout << 0;
        return 0;
    }
    if (ans > n)
    {
        cout << -1;
        return 0;
    }
    cout << ans + n - 1 - count_of_ones;
}