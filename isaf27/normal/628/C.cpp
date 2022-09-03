#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const int MAX_N = 100001;

typedef long long ll;
#define filename "test"
#define fin for (int i = 0; i < n; i++)
#define fim for (int i = 0; i < m; i++)
#define fjn for (int j = 0; j < n; j++)
#define fjm for (int j = 0; j < m; j++)

int n, k;
string s;

int main()
{
    //freopen(filename".in", "r", stdin);
    //freopen(filename".out", "w", stdout);
    cin >> n >> k;
    cin >> s;
    int summ = 0;
    for (int i = 0; i < n; i++)
        summ += max('z' - s[i], s[i] - 'a');
    if (summ < k)
    {
        cout << -1;
        return 0;
    }
    string ans = "";
    summ = 0;
    for (int i = 0; i < n; i++)
    {
        if (summ == k)
        {
            ans += s[i];
            continue;
        }
        if (summ + max('z' - s[i], s[i] - 'a') >= k)
        {
            int d = k - summ;
            if ('z' - s[i] > s[i] - 'a')
                ans += (s[i] + d);
            else
                ans += (s[i] - d);
            summ += d;
            continue;
        }
        if (s[i] - 'a' > 'z' - s[i])
        {
            ans += 'a';
            summ += s[i] - 'a';
            continue;
        }
        summ += 'z' - s[i];
        ans += 'z';
    }
    cout << ans;
    return 0;
}