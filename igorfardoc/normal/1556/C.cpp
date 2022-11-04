#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll res = 0;
    for(int i = 0; i < n; i += 2)
    {
        ll balance = 0;
        ll minadd = 0;
        for(int j = i + 1; j < n; j++)
        {
            if((j - i) % 2 == 1)
            {
                int left = a[i];
                int right = a[j];
                ll take = 0;
                if(balance > 0)
                {
                    right = max(0ll, right - balance);
                }
                else
                {
                    take = -balance;
                    left = max(0ll, left + balance);
                }
                if(take < minadd)
                {
                    right = max(0ll, right - (minadd - take));
                    left = max(0ll, left - (minadd - take));
                }
                res += min(left, right);
                //cout << i << ' ' << j << ' ' << res << endl;
                balance -= a[j];
            }
            else
            {
                balance += a[j];
            }
            minadd = max(minadd, -balance - 1);
        }
    }
    cout << res;
}