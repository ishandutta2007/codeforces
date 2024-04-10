/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mxn = 1e5;

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
    int n, d;
    cin>>n>>d;

    int x[d+1], y[d+1];
    for(int i=1; i<=d; i++) cin>>x[i]>>y[i];

    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=n; j++) make_set(j);

        int cnt=0;
        for(int j=1; j<=i; j++)
        {
            if(union_sets(x[j], y[j])) cnt++;
        }

        set<int> st;
        for(int j=1; j<=n; j++) st.insert(find_set(j));

        priority_queue<int> pq;
        for(int x: st) pq.push(siz[x]);

        int ans=0;
        while(!pq.empty() && cnt>=0)
        {
            ans+=pq.top();
            pq.pop();
            cnt--;
        }
        ans--;

        cout<<ans<<endl;
    }
}

int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}