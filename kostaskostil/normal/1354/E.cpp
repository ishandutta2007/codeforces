#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e3+100;
//typedef long long ll;
//#define int ll

int n, m;
vector<int> g[nmax];
int used[nmax];
vector<int> new_;

vector<vector<int> > a1, a2;

void dfs(int v){
    new_.pb(v);
    for (int i:g[v])
    {
        if (used[i]==used[v])
        {
            cout<<"NO\n";
            exit(0);
        }
        if (used[i]==0)
        {
            used[i]=3-used[v];
            dfs(i);
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n1, n2, n3;
    cin>>n>>m;
    cin>>n1>>n2>>n3;
    for (int x, y, i=1; i<=m; i++){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i=1; i<=n; i++)
        if (used[i]==0)
    {
        new_.clear();
        used[i]=1;
        dfs(i);
        vector<int> v1, v2;
        for (int i:new_)
            if (used[i]==1)
                v1.pb(i);
            else
                v2.pb(i);
        a1.pb(v1);
        a2.pb(v2);
    }

    m=a1.size();
    int t=n2;
    vector<vector<int>> v(m+1, vector<int>(t+1, 0));

//    for (int i=0; i<m; i++)
//    {
//        cout<<a1[i].size()<<" "<<a2[i].size()<<"\n";
//    }

    v[0][0]=1;
    for (int i=0; i<m; i++)
    for (int j=0; j<=t; j++)
    if (v[i][j]!=0)
    {
        if (j+a1[i].size() <= t)
            v[i+1][j+a1[i].size()]=1;
        if (j+a2[i].size() <= t)
            v[i+1][j+a2[i].size()]=2;
    }
    if (v[m][t]==0)
    {
        cout<<"NO\n";
        exit(0);
    }
    vector<int> pos;
    for (int i=m; i>0; i--){
        pos.pb(v[i][t]);
        if (v[i][t]==1)
            t-=a1[i-1].size();
        else t-=a2[i-1].size();
    }
    reverse(pos.begin(), pos.end());
    for (int i=0; i<m; i++)
        if (pos[i]==1)
            swap(a1[i], a2[i]);
    vector<int> ans(n);
    for (int i=0; i<m; i++)
        for (int j:a2[i])
            ans[j-1]=2;
    for (int i=0; i<m; i++)
        for (int j:a1[i])
            if (n1-- > 0)
                ans[j-1]=1;
            else ans[j-1]=3;

    cout<<"YES\n";
    for (int i:ans)
        cout<<i;
    cout<<"\n";

    return 0;
}