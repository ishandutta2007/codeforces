#include <bits\stdc++.h>
#define pb push_back
#define fi first
#define se second
//#define int long long

using namespace std;

int used[200500];
int p[200500];
int c[200500];
int n;
vector<int> v;
int ans()
{
    int n=v.size();
//    int m=0;
//    map<int, int> mp;
//    for (int i=0; i<n; i++)
//    {
//        if (mp[c[v[i]]]==0)
//            m++, mp[c[v[i]]]=m;
//        v[i]=mp[c[v[i]]];
//    }
    for (int i=0; i<n; i++)
        v[i]=c[v[i]];

    vector<int> dl;
    for (int i=1; i*i<=n; i++)
        if (n%i==0)
    {
        dl.pb(i);
        if (i*i!=n)
            dl.pb(n/i);
    }
    sort(dl.begin(), dl.end());

    for (int i:dl)
    {
        vector<int> bad;
        bad.resize(i);
        for (int j=0; j<n; j++)
            if (v[j]!=v[(j+i)%n])
                bad[j%i]=1;
        for (int j:bad)
            if (j==0)
            return i;
    }

}
void dfs(int vx)
{
    used[vx]=1;
    v.pb(vx);
    if (used[p[vx]]==0)
        dfs(p[vx]);
}

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
        memset(used, 0, sizeof(used));
        for (int i=1; i<=n; i++)
            cin>>p[i];
        for (int i=1; i<=n; i++)
            cin>>c[i];
        int answ=1e9;
        for (int i=1; i<=n; i++)
            if (used[i]==0)
        {
            v.clear();
            dfs(i);
            answ=min(answ, ans());
        }
        cout<<answ<<"\n";
    }
    return 0;
}