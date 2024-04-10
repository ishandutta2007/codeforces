#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int ans = 0;
    int tek = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            if (tek == 0) ans++;
            else tek--;
        }
        else
            tek += x;
    }

    cout << ans;

}