#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int n;
    int a[100], b[100];
    int ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        if (i != j)
    {
        ans += (b[j] == a[i]);
    }

    cout << ans;

}