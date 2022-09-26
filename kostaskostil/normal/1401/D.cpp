#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int long long

const int nmax=1e6+100;
vector<int> g[nmax];
int d[nmax];

int dfs(int v, int p=-1)
{
    int s=1;
    for (int i:g[v])
        if (i!=p)
            s+=dfs(i, v);
    d[v]=s;
    return s;
}
const int mod =1e9+7;
main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            g[i].clear();
        }
        for (int i=1; i<n; i++)
        {
            int u, v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1);
        int k;
        cin>>k;
        vector<int> v(k);
        for (int &i:v) cin>>i;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        vector<int> ans;
        for (int i=2; i<=n; i++)
            ans.pb(d[i]*(n-d[i]));

        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());

        int answ=0;
        n--;

//        for (int i=0; i<k-n; i++)
//            answ+=ans[0]*v[i], answ%=mod;
//        for (int i=max(0ll, k-n); i<k; i++)
//            answ+=ans[i-max(0ll, k-n)]*v[i], answ%=mod;
        if (k<n)
        {
            for (int i=0; i<k; i++)
                answ+=ans[i]*v[i], answ%=mod;
            for (int i=k; i<n; i++)
                answ+=ans[i], answ%=mod;
        }
        else
        {
            for (int i=1; i<n; i++)
                answ+=v[i-(n-k)]*ans[i], answ%=mod;
            int p=1;
            for (int i=0; i<k-n+1; i++)
                p*=v[i], p%=mod;
            answ+=ans[0]*p;
            answ%=mod;
        }
        cout<<answ<<"\n";
    }

    return 0;
}