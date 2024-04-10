#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> to_vector(int n)
{
    vector<int> res;
    while(n)
    {
        res.push_back(n % 10);
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
int to_int(vector<int> a)
{
    int res = 0;
    int now = 1;
    for(int i = (int)a.size() - 1; i >= 0; i--)
    {
        res += a[i] * now;
        now *= 10;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        auto a = to_vector(n);
        if(k == 1)
        {
            bool ok = true;
            for(int i = 0; i < a.size(); i++)
            {
                if(a[i] != a[0])
                {
                    ok = false;
                    if(a[i] > a[0])
                    {
                        for(int j = 0; j < a.size(); j++)
                        {
                            cout << a[0] + 1;
                        }
                        cout << '\n';
                        break;
                    }
                    else
                    {
                        for(int j = 0; j < a.size(); j++)
                        {
                            cout << a[0];
                        }
                        cout << '\n';
                        break;
                    }
                }
            }
            if(ok)
            {
                for(int j = 0; j < a.size(); j++)
                {
                    cout << a[0];
                }
                cout << '\n';
            }
            continue;
        }
        vector<set<int>> sets(a.size());
        set<int> now;
        vector<int> ans(a.size());
        for(int i = 0; i < a.size(); i++)
        {
            now.insert(a[i]);
            sets[i] = now;
            if(now.size() > k)
            {
                auto it = sets[i - 1].lower_bound(a[i]);
                if(it != sets[i - 1].end())
                {
                    int min1 = *(sets[i - 1].begin());
                    for(int j = 0; j < i; j++)
                    {
                        ans[j] = a[j];
                    }
                    ans[i] = *it;
                    for(int j = i + 1; j < a.size(); j++)
                    {
                        ans[j] = min1;
                    }
                    break;
                }
                for(int j = i - 1; j >= 0; j--)
                {
                    set<int> set1;
                    if(j != 0)
                    {
                        set1 = sets[j - 1];
                    }
                    int fill1 = a[j] + 1;
                    if(set1.size() == k)
                    {
                        auto it = set1.upper_bound(a[j]);
                        if(it != set1.end())
                        {
                            fill1 = *it;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if(fill1 > 9)
                    {
                        continue;
                    }
                    set1.insert(fill1);
                    int min1 = *(set1.begin());
                    if(set1.size() < k)
                    {
                        min1 = 0;
                    }
                    for(int v = 0; v < j; v++)
                    {
                        ans[v] = a[v];
                    }
                    ans[j] = fill1;
                    for(int v = j + 1; v < a.size(); v++)
                    {
                        ans[v] = min1;
                    }
                    break;

                }
                break;
            }
            if(i == (int)a.size() - 1)
            {
                ans = a;
            }
        }
        for(int i = 0; i < a.size(); i++)
        {
            cout << ans[i];
        }
        cout << '\n';
    }
}