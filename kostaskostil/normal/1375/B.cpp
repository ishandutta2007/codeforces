#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    for (int iii=0; iii<qqq; iii++)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int> > v(n, vector<int>(m));
        vector<vector<int> > u(n, vector<int>(m));
        bool good=true;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
            {
                cin>>v[i][j];
                u[i][j]=(i!=0)+(i!=(n-1))+(j!=0)+(j!=(m-1));
                if (v[i][j]>u[i][j])
                    good=false;
            }
        if (good)
        {
            cout<<"YES\n";
            for (int i=0; i<n; i++, cout<<"\n")
                for (int j:u[i])
                    cout<<j<<" ";
        }
        else cout<<"NO\n";

    }
}