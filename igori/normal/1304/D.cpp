#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define prev prev228
#define all(x) (x).begin(), (x).end()
#define int long long

int a[500000], b[500000];

int solve()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s.size(); i++) if (s[i] == '<') cnt1++; else cnt2++;
    for (int i = 0; i < n; i++) a[i] = i + 1, b[i] = i + 1;
    reverse(a, a + n);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '<')
        {
            int r = i;
            while (r + 1 < s.size() && s[r + 1] == '<')
            {
                r++;
            }
            reverse(a + i, a + r + 2);
            i = r;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '>')
        {
            int r = i;
            while (r + 1 < s.size() && s[r + 1] == '>')
            {
                r++;
            }
            reverse(b + i, b + r + 2);
            i = r;
        }
    }
    
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}