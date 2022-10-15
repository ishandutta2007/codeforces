/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<int> a[n], b[n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int x; cin>>x;
            a[i].push_back(x);
            b[i].push_back(x);
        }
        sort(b[i].begin(), b[i].end());
    }

    set<int> st;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j]!=b[i][j]) st.insert(j);
        }
    }

    int ss = st.size();
    if(ss>2) { cout<<-1<<endl; return; }
    if(ss==0) { cout<<1<<" "<<1<<endl; return; }

    auto itr = st.begin();
    int j1 = *itr;

    itr++;
    int j2 = *itr;

    for(int i=0; i<n; i++) swap(a[i][j1], a[i][j2]);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j]!=b[i][j]) { cout<<-1<<endl; return; }
        }
    }

    cout<<j1+1<<" "<<j2+1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}