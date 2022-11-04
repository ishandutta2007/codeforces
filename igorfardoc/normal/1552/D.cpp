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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool ok = false;
        for(int mask1 = 0; mask1 < (1 << n); ++mask1)
        {
            for(int mask2 = 0; mask2 < (1 << n); ++mask2)
            {
                if(mask1 == 0 && mask2 == 0)
                {
                    continue;
                }
                int sum1 = 0;
                int sum2 = 0;
                bool ok1 = true;
                for(int i = 0; i < n; i++)
                {
                    if(((mask1 >> i) & 1) && ((mask2 >> i) & 1))
                    {
                        ok1 = false;
                        break;
                    }
                    if((mask1 >> i) & 1)
                    {
                        sum1 += a[i];
                    }
                    if((mask2 >> i) & 1)
                    {
                        sum2 += a[i];
                    }
                }
                if(ok1 && sum1 == sum2)
                {
                    ok = true;
                    break;
                }
            }
            if(ok)
            {
                break;
            }
        }
        if(ok)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << '\n';
    }
}