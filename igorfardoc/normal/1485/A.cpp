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
        int a, b;
        cin >> a >> b;
        int ans = 1000000000;
        for(int i = 0; i < 100000; i++)
        {
            int b1 = i + b;
            if(b1 > a)
            {
                ans = min(ans, i + 1);
                continue;
            }
            if(b1 == 1)
            {
                continue;
            }
            int a1 = a;
            int now = 0;
            while(a1 > 0)
            {
                a1 = a1 / b1;
                ++now;
            }
            ans = min(ans, now + i);
        }
        cout << ans << '\n';
    }
}