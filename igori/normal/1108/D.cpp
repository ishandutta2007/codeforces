#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i != (n); i++)
#define fi first
#define se second
#define pb push_back
#define sz size()

int n;

int main()
{
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            if (i + 2 < n && s[i + 1] == s[i + 2])
            {
                s[i + 1] = 'R';
                if (s[i] == 'R')
                    s[i + 1] = 'B';
                ans++;
            }
            else
            if (i + 2 < n)
            {
                ans++;
                s[i + 1] = 'R' + 'G' + 'B' - s[i] - s[i + 2];
            }
            else
            {
                ans++;
                s[i + 1] = 'R';
                if (s[i] == 'R')
                    s[i + 1] = 'B';
            }
        }
    }
    cout << ans << "\n" << s;
}