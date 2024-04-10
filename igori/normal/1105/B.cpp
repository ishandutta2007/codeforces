#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
int n, k;
string s;

int get(char c)
{
    int cnt = 0;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        if (cnt >= k)
        {
            res++;
            cnt = 0;
        }
    }
    return res;
}

signed main()
{
    cin >> n >> k;
    cin >> s;
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        ans = max(ans, get(c));
    }
    cout << ans;
}