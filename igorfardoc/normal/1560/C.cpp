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
        int k;
        cin >> k;
        for(int i = 1;; i++)
        {
            if(k <= (ll)i * i)
            {
                int r = 1;
                int c = i;
                int here = (ll)(i - 1) * (i - 1) + 1;
                while(here != k)
                {
                    ++here;
                    if(r < c)
                    {
                        ++r;
                    }
                    else
                    {
                        --c;
                    }
                }
                cout << r << ' ' << c << '\n';
                break;
            }
        }
    }
}