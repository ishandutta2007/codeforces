#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()

int main()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    char c = 'z';
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= c)
        {
            s[i] = c;
            if (c == 'a')
            {
                c = 0;
                break;
            }
            c--;
        }
    }
    reverse(s.begin(), s.end());
    if (c == 0) cout << s << "\n";
    else cout << -1 << "\n";
}