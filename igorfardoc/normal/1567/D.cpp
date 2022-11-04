#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s, n;


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
        cin >> s >> n;
        vector<int> a(n);
        int now = 1000000000;
        while(now > 0)
        {
            int free = 0;
            for(int i = 0; i < n; i++)
            {
                if(a[i] == 0)
                {
                    ++free;
                }
            }
            for(int i = 9 * n; i >= 0; i--)
            {
                int freehere = max(0, free - i);
                if((ll)now * i + freehere > s)
                {
                    continue;
                }
                int amount = i;
                for(int j = 0; j < n; j++)
                {
                    if(amount == 0)
                    {
                        break;
                    }
                    if(a[j] == 0)
                    {
                        a[j] = now;
                        --amount;
                    }
                }
                for(int j = 0; j < n; j++)
                {
                    if(amount == 0)
                    {
                        break;
                    }
                    int here = min(amount, 9 - a[j] / now % 10);
                    a[j] += here * now;
                    amount -= here;
                }
                s -= i * now;
                break;
            }
            now /= 10;
        }
        for(int i = 0; i < n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}