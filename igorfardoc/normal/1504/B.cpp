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
        string a, b;
        cin >> a >> b;
        int prev = 0;
        int am0 = 0;
        int am1 = 0;
        bool ok = true;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == '0')
            {
                ++am0;
            }
            else
            {
                ++am1;
            }
            if(am0 == am1)
            {
                bool rev = !(a[prev] == b[prev]);
                for(; prev <= i; prev++)
                {
                    if((a[prev] - '0') != rev ^ (b[prev] - '0'))
                    {
                        cout << "NO\n";
                        ok = false;
                        break;
                    }
                }
                if(!ok)
                {
                    break;
                }
                prev = i + 1;
                am0 = 0;
                am1 = 0;
            }
        }
        if(ok)
        {
            for(int i = prev; i < n; i++)
            {
                if(a[i] != b[i])
                {
                    cout << "NO\n";
                    ok = false;
                    break;
                }
            }
        }
        if(ok)
        {
            cout << "YES\n";
        }
    }
}