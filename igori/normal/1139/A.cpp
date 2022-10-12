#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n;
string s;
long long ans = 0;
int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] - '0') % 2 == 0)
            ans += i + 1;
    }
    cout << ans;
}