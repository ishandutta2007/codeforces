#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s;
    cin >> s;

    int l = 0;
    int ans = 0;
    for (int i = 0; i < (int) s.size() - 3; i++)
    {
        if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r')
        {
            ans += (i - l + 1) * ((int) s.size() - i - 3);
            l = i + 1;
        }
    }

    cout << ans;

}