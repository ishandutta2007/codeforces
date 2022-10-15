/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mxn = 2e5 + 100;

int parent[mxn];
int siz[mxn];

//use make_set, find_set and union_sets properly
void make_set(int v)
{
    parent[v] = v;
    siz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b) return true;
    if (siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
    return false;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++) make_set(i);

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    for(int i=1; i<=n; i++) union_sets(a[i], b[i]);

    map<int, int> mp;
    vector<int> cyc;

    for(int i=1; i<=n; i++)
    {
        int x = find_set(i);
        if(mp[x]==1) continue;
        cyc.push_back(siz[x]);
        mp[x]=1;
    }

    sort(cyc.begin(), cyc.end());
    int m = cyc.size();
    int ans=0, lft=n;

    for(int i=0; i<m; i++)
    {
        int x = cyc[i];
        if(x==1) continue;

        lft-=x;
        x--;

        int y=x/2;
        int tmp = (y*(y+1)*2);

        int big=x;
        if(x%2==1)
        {
            big=x+1;
            tmp+=big;
        }

        tmp += (lft*big);
        ans+=tmp;
        if(x%2==0) lft++;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}