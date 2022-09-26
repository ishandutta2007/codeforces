#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

#define int long long

using namespace std;

const int nmax=2e5+100;
int a[nmax];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i], a[i]+=a[i-1];
    map<int, vector<int> > pos;
    for (int i=0; i<=n; i++)
        pos[a[i]].pb(i);
    set<pair<int, int> > bad;
    for (auto pa:pos)
        for (int i=0; i+1<pa.second.size(); i++)
            bad.insert({pa.second[i], pa.second[i+1]});
    int firstr=n+1;
    int ans=0;
    for (int i=n; i>=0; i--)
    {
        while (!bad.empty())
        {
            auto it=prev(bad.end());
            if ((*it).fi>=i)
                firstr=min(firstr, (*it).se), bad.erase(it);
            else
                break;
        }
        ans+=firstr-i;
    }
    cout<<ans-n-1<<"\n";
}