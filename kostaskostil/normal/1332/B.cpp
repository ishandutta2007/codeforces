#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long
using namespace std;

const int nmax=1010;
int a[nmax];
int n;
vector<int> pr={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        vector<vector<int> > ans;
        ans.resize(11);
        for (int i=1; i<=n; i++)
            for (int j=0; j<11; j++)
                if (a[i]%pr[j]==0)
            {
                    ans[j].pb(i);
                    break;
            }
        set<vector<int> > ansx;
        for (auto v:ans)
            ansx.insert(v);
        vector<int> p;
        ansx.erase(p);
        p.resize(n+1);
        int c=0;
        for (auto v:ansx)
        {
            c++;
            for (int i:v)
                p[i]=c;
        }

        cout<<ansx.size()<<"\n";
        for (int i=1; i<=n; i++)
            cout<<p[i]<<" ";
        cout<<"\n";
    }

}