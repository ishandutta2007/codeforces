#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{

    int a, b, c = 0;
    cin >> a >> b;
    int ans = 0;

    while (a)
    {
        ans += a;
        int anew = (a + c) / b;
        c = a + c - anew * b;
        a = anew;
    }

    cout << ans;

}