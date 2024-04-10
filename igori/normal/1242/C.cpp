#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
#define int long long
const int N = 500;

int k;
int n[50];
int summ[50];
set<int> val[50];
map<int, int> where;
int key[(1 << 15)];
int take[1 << 15];
int dp[(1 << 15)];
int pre[1 << 15];
int si;

int c[50], p[50];

signed main()
{
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n[i];
        for (int j = 0; j < n[i]; j++)
        {
            int x;
            cin >> x;
            where[x] = i;
            si += x;
            summ[i] += x;
            val[i].insert(x);
        }
    }
    if (si % k != 0)
    {
        cout << "No";
        return 0;
    }
    si /= k;
    for (int i = 0; i < k; i++)
    {
        vector<int> cur_summ(k);
        for (auto elem : val[i])
        {
            for (int j = 0; j < k; j++)
            {
                cur_summ[j] = summ[j];
            }
            int mask = (1 << i);
            cur_summ[i] -= elem;
            int store = elem;
            int need = si - cur_summ[i];
            int we = i;
            int t = 1;
            while (1)
            {
                if (where.find(need) == where.end())
                {
                    t = 0;
                    break;
                }
                int w = where[need];
                if (w == i && need == store) break;
                if (mask & (1 << w))
                {
                    t = 0;
                    break;
                }
                mask += (1 << w);
                cur_summ[we] += need;
                cur_summ[w] -= need;
                need = si - cur_summ[w];
                we = w;
            }
            if (t)
            {
                dp[mask] = 1;
                pre[mask] = mask;
                key[mask] = 1;
                take[mask] = elem;
            }
        }
    }
    for (int mask = 0; mask < (1 << k); mask++)
    {
        for (auto submask = mask; ; submask = (submask - 1) & mask)
        {
            if (key[submask] && dp[mask - submask])
            {
                dp[mask] = 1;
                pre[mask] = submask;
            }
            if (submask == 0) break;
        }
    }
    if (dp[(1 << k) - 1] == 0)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    vector<int> combi;
    int m = (1 << k) - 1;
    while (m > 0)
    {
        combi.push_back(pre[m]);
        m -= pre[m];
    }
    for (auto mask : combi)
    {
        int elem = take[mask];
        int i = where[elem];
        vector<int> cur_summ(k);

        for (int j = 0; j < k; j++)
        {
            cur_summ[j] = summ[j];
        }
        cur_summ[i] -= elem;
        int store = elem;
        int need = si - cur_summ[i];
        int we = i;
        c[we] = elem;
        int t = 1;
        while (1)
        {
            int w = where[need];
            p[w] = we;
            if (w == i && need == store) break;
            cur_summ[we] += need;
            cur_summ[w] -= need;
            c[w] = need;
            need = si - cur_summ[w];
            we = w;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << c[i] << " " << p[i] + 1 << "\n";
    }
}