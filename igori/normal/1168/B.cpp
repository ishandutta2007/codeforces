#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
string s;
ll ans = 0;

bool ok(int i, int j)
{
    if (j - i + 1 >= 3)
    {
        for (int x = i; x <= j; x++)
        {
            for (int k = 1; 2 * k + x <= j; k++)
            {
                if (s[x] == s[x + k] && s[x + k] == s[x + 2 * k])
                    return 1;
            }
        }
        return 0;
    }
    return 0;
}

int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (ok(i, j))
            {
                ans += s.size() - j;
                break;
            }
        }
    }
    cout << ans;
}