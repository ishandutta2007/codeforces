#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const long long MOD = 11;
string s;

long long In[500000];
long long cnt[500000];
long long num[500000];
long long d[500000];
long long demonstrated[12][12][12];
long long ok[500000];

long long lg10(long long x)
{
    if (1 <= x && x <= 9)
        return 1;
    return lg10(x / 10) + 1;
}

int graph[5000][10];

struct trio{
    int a, b, c;
};

long long num_by_trio(trio A)
{
    return A.a * 121 + A.b * 11 + A.c;
}

trio get(int i)
{
    return {In[i] % 11, (In[i] - d[lg10(i) - 1] + 11) % 11, (d[lg10(i)] - In[i] + 11 * 11 * 11 * 11) % 11};
}

vector<long long> dp(1500);
long long ans = 0;

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        In[i] = i;
    }
    for (int i = 10; i <= 100000; i++)
    {
        if (In[i / 10] && i % 10 < In[i / 10] % 11)
        {
            int j = i;
            while (In[j] == 0)
                j--;
            In[i] = In[j] + 1;
        }
        if (In[i])
        {
            cnt[lg10(i)]++;
        }
    }
    cnt[1] = 9;
    for (int i = 1; i <= 10; i++)
    {
        d[i] = (d[i - 1] + cnt[i]) % 11;
    }
    for (int i = 0; i < 1331; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            graph[i][j] = -1;
        }
    }
    for (int i = 10; i <= 100000; i++)
    {
        if (In[i])
        {
            graph[num_by_trio(get(i / 10))][i % 10] = num_by_trio(get(i));
            ok[num_by_trio(get(i / 10))] = 1;
            //cout << num_by_trio(get(i / 10)) << " " << i % 10 << " " << num_by_trio(get(i)) << endl;
        }
    }
    //for (int i = 0; i < 1331; i++)
    //{
    //    cout << ok[i];
    //}
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        vector<long long> dp2(1500);
        if (s[i] != '0')
            dp2[num_by_trio(get(s[i] - '0'))] = 1;
        if (i + 1 < s.size())
        {
            for (int j = 0; j < 1331; j++)
            {
                long long k = graph[j][s[i + 1] - '0'];
                if (k == -1) continue;
                dp2[j] += dp[k] + 1;
            }
        }
        if (s[i] - '0' != 0)
            ans += dp2[num_by_trio(get(s[i] - '0'))];
        dp = dp2;
    }
    cout << endl << ans;
}