#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int n, m;

int main()
{
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            cout << ans;
            ans = 0;
        }
        else
            ans++;
    }
    cout << ans;
}