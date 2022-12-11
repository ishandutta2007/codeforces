#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int n;
    int ans[120];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        ans[x] = i;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";

}