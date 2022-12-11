#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n;
    int ans = 0;

    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ans += (a + b + c > 1);
    }

    cout << ans;

}