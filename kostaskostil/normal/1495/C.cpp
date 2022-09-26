#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
//#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    while (___--)
    {
        int n, m;
        cin>>n>>m;
        vector<string> v(n);
        for (int i=0; i<n; i++)
            cin>>v[i];
        for (int i=0; i<n; i+=3)
            v[i]=string(m, 'X');
        for (int i=2; i<n; i+=3)
        {
            bool ok = false;
            for (int j=0; j<m; j++)
            {
                if (v[i][j] == 'X')
                {
                    if (i+1 == n)
                    {
                        v[i-1][j]='X';
                        ok=true;
                    }
                    else
                    {
                        if (!ok)
                            v[i-1][j]='X', ok=true;
                    }
                }
                if (v[i-1][j] == 'X')
                    if (!ok)
                        v[i][j]='X', ok=true;
            }
            if (!ok)
                v[i][0]=v[i-1][0]='X';
        }

        for (int i=0; i<n; i++)
            cout<<v[i]<<"\n";
    }
}