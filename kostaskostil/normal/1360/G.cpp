#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

vector<vector<int> > f(int n, int m, int a, int b)
{
    vector<vector<int> > v(n, vector<int>(m, 0));
    int cur=0;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<b; j++)
            v[(cur+j)%n][i]=1;
        cur=(cur+b)%n;
    }
    for (int i=0; i<n; i++)
    {
        int cnt=0;
        for (int j=0; j<m; j++)
            cnt+=v[i][j];
        if (cnt!=a)
        {
            v.clear();
            return v;
        }
    }
    return v;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt=0;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n, m, a, b;
        cin>>n>>m>>a>>b;
        auto res1=f(n, m, a, b);
        auto res2=f(m, n, b, a);
        if (res2.size()!=0)
        {
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    res1[i][j]=res2[j][i];
        }
        if (res1.size())
        {
            cout<<"YES\n";
            for (int i=0; i<n; i++, cout<<"\n")
                for (int j=0; j<m; j++)
                    cout<<res1[i][j];
        }
        else
            cout<<"NO\n";
    }
}