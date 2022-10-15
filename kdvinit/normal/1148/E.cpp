/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 3e5 + 100;
pair<int, int> a[N];
int b[N];

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    { 
        int x; cin>>x;
        a[i] = {x, i};
    }
    
    for(int i=1; i<=n; i++) cin>>b[i];

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    vector<array<int, 2>> pos, neg;
    int sum=0;

    for(int i=1; i<=n; i++)
    {
        int dif = b[i]-a[i].first;
        int jj = a[i].second;
        sum+=dif;

        if(sum<0) { cout<<"NO"<<endl; return; }

        if(dif==0) continue;
        if(dif>0) pos.push_back({dif, jj});
        else neg.push_back({-dif, jj});
    }

    if(sum!=0) { cout<<"NO"<<endl; return; }

    cout<<"YES"<<endl;

    vector<array<int, 3>> ans;

    n = pos.size();
    int m = neg.size();

    int i=0;
    int j=0;

    while(1)
    {
        if(i>=n && j>=m) break;
        int d = min(pos[i][0], neg[j][0]);

        ans.push_back({pos[i][1], neg[j][1], d});

        pos[i][0]-=d;
        neg[j][0]-=d;

        if(pos[i][0]==0) i++;
        if(neg[j][0]==0) j++;

        if(i>=n && j>=m) break;
        if(i>=n || j>=m) { cout<<"Fuck"<<endl; break; }
    }

    cout<<ans.size()<<endl;
    for(auto x: ans)
    {
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}