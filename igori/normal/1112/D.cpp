#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
#define re return
#define pb push_back
#define fi first
#define se second
#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)

const long long MOD = 1e9 + 7;
ll n, a, b;
string s;
ll dp[5010];

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin >> n >> a >> b;
    cin >> s;
    s = "0" + s;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        dp[i] = MOD;
    for (int id = 1; id <= n; id++)
    {
        dp[id] = dp[id - 1] + a;
        vector<char> c;
        for (int j = id; j > 0; j--)
        {
            c.push_back(s[j]);
        }
        vector<int> z(c.size());
        int L = 0, R = 0;
        z[0] = c.size();
        for (int i = 1; i < c.size(); i++)
        {
            //cout << "bbb" << endl;
            z[i] = max(0, min(R - i, z[i - L]));
            //cout << "aaa" << endl;
            while (i + z[i] < c.size() && c[z[i]] == c[i + z[i]])
                z[i]++;
            //cout << z[i] << endl;
            if (i + z[i] > R)
            {
                R = i + z[i];
                L = i;
            }
        }
        //cout << "COME" << endl;
        vector<int> suffix_maximums(c.size() + 1);
        for (int i = c.size() - 1; i >= 0; i--)
        {
            if (i == c.size() - 1)
            {
                suffix_maximums[i] = z[i];
                continue;
            }
            suffix_maximums[i] = max(suffix_maximums[i + 1], z[i]);
            //cout << suffix_maximums[i] << " ";
        }
        //cout << endl;
        long long len = 1;
        while (len <= id)
        {
            if (suffix_maximums[len] >= len)
            {
                //cout << id << " " << len << endl;
                dp[id] = min(dp[id], dp[id - len] + b);
            }
            len++;
        }
    }
    cout << dp[n];
}