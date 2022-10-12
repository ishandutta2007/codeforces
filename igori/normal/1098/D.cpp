#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

map<int, int> cnt[40];
long long summ[40];

void add(int x)
{
    for (int i = 0; i < 31; i++)
    {
        if ((1LL << i) <= x && x < (1LL << (i + 1)))
        {
            cnt[i][x]++;
            summ[i] += x;
            return;
        }
    }
}

void del(int x)
{
    for (int i = 0; i < 31; i++)
    {
        if ((1LL << i) <= x && x < (1LL << (i + 1)))
        {
            cnt[i][x]--;
            summ[i] -= x;
            if (cnt[i][x] == 0)
                cnt[i].erase(x);
            return;
        }
    }
}

int get()
{
    long long res = 0;
    long long summ_less = 0;
    for (int i = 0; i < 32; i++)
    {
        auto it = cnt[i].begin();
        pair<int, int> p = *it;
        if (cnt[i].size() > 0)
        if (p.first > 2 * summ_less)
            res++;
        summ_less += summ[i];
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    int ans = 0;
    for (int i = 0; i < q; i++)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
        {
            add(x);
            ans++;
        }
        else
        {
            del(x);
            ans--;
        }
        cout << ans - get() << "\n";
    }
}