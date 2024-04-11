#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
#define int ll

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int& i : v)
            cin>>i;
        bool b = true;
        for (int i=0; i<n; i++)
        {
            bool d = true;
            for (int j=2; j<=i+2; j++)
            {
                if (v[i] % j != 0)
                {
                    d = false;
                    break;
                }
            }
            if (d)
                b = false;
        }
        if (b)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}