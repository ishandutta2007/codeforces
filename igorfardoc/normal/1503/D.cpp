#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> a;
vector<bool> sc;
vector<int> suff;


int get_ans(int l, int r)
{
    int a1 = 2 * n;
    int a2 = 2 * n + 1;
    int ans = 0;
    for(int i = l; i <= r; i++)
    {
        if(a[i] > a1 && a[i] > a2)
        {
            return -1;
        }
        if(min(a1, a2) < a[i])
        {
            if(a1 < a2)
            {
                if(sc[i])
                {
                    ++ans;
                }
                a2 = a[i];
            }
            else
            {
                if(!sc[i])
                {
                    ++ans;
                }
                a1 = a[i];
            }
        }
        else
        {
            if(sc[i])
            {
                if(a1 < a2 || suff[i] < a2)
                {
                    a1 = a[i];
                }
                else
                {
                    a2 = a[i];
                    ++ans;
                }
            }
            else
            {
                if(a2 < a1 || suff[i] < a1)
                {
                    a2 = a[i];
                }
                else
                {
                    a1 = a[i];
                    ++ans;
                }
            }
        }
    }
    return min(ans, r - l + 1 - ans);
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
    cin >> n;
    a.resize(n);
    sc.assign(n, false);
    suff.resize(n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if((x <= n && y <= n) || (x > n && y > n))
        {
            cout << -1;
            return 0;
        }
        --x;
        --y;
        if(x > y)
        {
            swap(x, y);
            sc[x] = true;
        }
        a[x] = y;
    }
    vector<int> suff1(n), pref(n);
    suff1[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        suff1[i] = max(suff1[i + 1], a[i]);
    }
    suff[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--)
    {
        suff[i] = max(suff[i + 1], a[i + 1]);
    }
    pref[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        pref[i] = min(pref[i - 1], a[i]);
    }
    int ans = 0;
    int prev = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if(pref[i] > suff1[i + 1])
        {
            int res = get_ans(prev, i);
            if(res == -1)
            {
                cout << -1;
                return 0;
            }
            ans += res;
            prev = i + 1;
        }
    }
    int res = get_ans(prev, n - 1);
    if(res == -1)
    {
        cout << -1;
        return 0;
    }
    ans += res;
    cout << ans;
}