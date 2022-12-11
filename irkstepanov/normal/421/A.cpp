#include <iostream>

using namespace std;

int main()
{

    int n, ans[200];

    cin >> n;
    for (int i = 1; i <= n; i++)
    ans[i] = 2;
    int a, b;
    cin >> a >> b;

    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        ans[x] = 1;
    }

    for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";

}