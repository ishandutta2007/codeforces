#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n;
    cin >> n;
    char prev;

    cin >> prev;
    int ans = 0;
    n--;
    while (n--)
    {
        char t;
        cin >> t;
        if (t != prev) prev = t;
        else ++ans;
    }

    cout << ans;

}