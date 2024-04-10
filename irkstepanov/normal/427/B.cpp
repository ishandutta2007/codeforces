#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int t, c;
    cin >> t >> c;
    int ans = 0, more = 0;
    int a[200500];

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > t) more++;
        if (i >= c)
        {
            if (a[i - c] > t) more--;
            if (more == 0) ans++;
        }
    }

    cout << ans;

}