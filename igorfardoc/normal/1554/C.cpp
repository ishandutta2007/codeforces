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
        int n, m;
        cin >> n >> m;
        if(m < n)
        {
            cout << "0\n";
            continue;
        }
        bool ok = false;
        int ans = 0;
        m += 1;
        for(int i = 29; i >= 0; i--)
        {
            if(((n >> i) & 1) && !((m >> i) & 1))
            {
                break;
            }
            if(!((n >> i) & 1) && ((m >> i) & 1))
            {
                ans ^= (1 << i);
            }
        }
        cout << ans << '\n';
    }
}