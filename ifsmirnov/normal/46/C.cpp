#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int inf = 1e9;

int solve (string s)
{
    s = s + s;
    int lim = count(s.begin(), s.end(), 'H') / 2;
        
    int cur = 0, mx = 0;
    cur = count(s.begin(), s.begin() + lim, 'H');
    for (int i = 0; i < s.size() - lim; i++)
    {
        mx = max(mx, cur);
        if (s[i] == 'H')
            cur--;
        if (s[i + lim] == 'H')
            cur++;
    }
    mx = max(mx, cur);
    return lim - mx;
};

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string t;
    cin >> t >> t;
    cout << solve(t);
    return 0;
}