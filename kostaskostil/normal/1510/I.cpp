#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long double ld;

int mistakes[1010];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    for (int i = 0; i<m; i++)
    {
        string s;
        cin>>s;
        vector<int> v(n);
        for (int i=0; i<n; i++)
            v[i] = (s[i]-'0');

        int mn = 1e9;
        for (int i=0; i<n; i++)
            mn=min(mn, mistakes[i]);

        double sumw = 0;
        for (int i=0; i<n; i++)
            sumw += exp( (mn - mistakes[i]) * log( 2 ));
        sumw = rand()*1.0/RAND_MAX*sumw;
        for (int i=0; i<n; i++)
        {
            sumw -= exp( (mn - mistakes[i]) * log( 2 ));
            if (sumw<0)
            {
                cout<<v[i]<<endl;
                break;
            }
        }
        int c;
        cin>>c;
        for (int i=0; i<n; i++)
            if (c!=v[i])
                mistakes[i]++;
    }
}