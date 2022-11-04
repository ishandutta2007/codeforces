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
        int q, d;
        cin >> q >> d;
        bitset<10001> b;
        for(int i = 1; i <= 10000; i++)
        {
            int ch = i;
            bool ok = false;
            while(ch > 0)
            {
                int here = ch % 10;
                if(here == d)
                {
                    ok = true;
                    break;
                }
                ch /= 10;
            }
            if(ok)
            {
                b[i] = true;
                for(int j = 0; j < 10001 / i; j++)
                {
                    b |= (b << i);
                }
            }
        }
        for(int i = 0; i < q; i++)
        {
            int val;
            cin >> val;
            if(val > 10000 || b[val])
            {
                cout << "YES\n";
                continue;
            }
            cout << "NO\n";
        }
    }
}