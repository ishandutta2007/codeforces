#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 5e5 + 100;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    while (qqq--)
    {
        int n, m;
        cin>>n>>m;
        vector<string> v(n);
        for (string& s : v)
            cin>>s;
        int red = -1;
        bool f = true;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
        {
            if (v[i][j] == 'R')
            {
                if (red == -1)
                    red = (i + j)%2;
                if (red != (i+j)%2)
                    f = false;
            }
            if (v[i][j] == 'W')
            {
                if (red == -1)
                    red = (i + j + 1)%2;
                if (red != (i+j + 1)%2)
                    f = false;
            }
        }
        if (!f){
            cout<<"NO\n";
            continue;
    }
    cout<<"YES\n";
        if (red<0)
            red = 0;
        for (int i=0; i<n; i++, cout<<"\n")
            for (int j=0; j<m; j++)
        {
            if ((i+j)%2 == red)
                cout<<"R";
            else
                cout<<"W";
        }
    }
}