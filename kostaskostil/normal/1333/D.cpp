#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

#define int long long

using namespace std;

const int nmax=2e5+100;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    string s;
    cin>>s;
    for (int i=0; i<n; i++)
        if (s[i]=='L') a[i]=-1;
        else a[i]=1;
    int sum=0;
    vector<vector<int> > pos;
    while (true)
    {
        vector<int> nt;
        for (int i=0; i<n-1; i++)
            if (a[i]==1 and a[i+1]==-1)
                nt.pb(i), a[i]=-1, a[i+1]=1, i++;
        if (nt.empty())
            break;
        sum+=nt.size();
        pos.pb(nt);
    }
    if ((sum<k) or (pos.size()>k))
        cout<<-1<<"\n", exit(0);
    int cur=0;
    for ( ;k>0; k--)
    {
        int x= min<int>(sum-k+1, pos[cur].size());
        cout<<x<<" ";
        for (int i=pos[cur].size()-x; i<pos[cur].size(); i++)
            cout<<pos[cur][i]+1<<" ";
        cout<<"\n";

        pos[cur].resize(pos[cur].size()-x);
        if (pos[cur].empty())
            cur++;
        sum-=x;
    }
}