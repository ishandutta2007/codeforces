#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

const string match = "abacaba";
bool check(string s, int k)
{
    int cnt = 0;
    for (int i = 0; i < 7; ++i)
    {
        if (s[k + i] == '?')
            s[k + i] = match[i];
        else if (s[k + i] != match[i])
            return false;
    }
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '?')
            s[i] = 'z';
    for (int i = 0; i < s.size(); ++i)
        if (s.substr(i, 7) == match)
            cnt++;
    if (cnt == 1)
    {
        cout << "Yes\n" << s << '\n';
        return true;
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        bool flag = false;
        for (int i = 0; i < n - 6; ++i)
            if (check(s, i))
            {
                flag = true;
                break;
            }
        if (!flag)
            cout << "No" << '\n';
    }
    return 0;
}