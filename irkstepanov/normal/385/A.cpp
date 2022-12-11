#include <iostream>

using namespace std;

int main()
{

    int n, c;
    int x[120];

    cin >> n >> c;
    int ans = 0;

    for (int i = 1; i <= n; i++)
        cin >> x[i];

    for (int d = 1; d < n; d++)
    {
        ans = max(ans, x[d] - x[d + 1] - c);
    }

    cout << ans;

}