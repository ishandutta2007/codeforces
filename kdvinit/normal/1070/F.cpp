/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    map<string, int> mp;
    mp["00"]=4;
    mp["01"]=3;
    mp["10"]=2;
    mp["11"]=1;

    vector<int> a[5];
    for(int i=1; i<=n; i++)
    {
        string s; cin>>s;
        int x; cin>>x;
        int y = mp[s];
        a[y].push_back(-x);
    }
    sort(a[1].begin(), a[1].end());
    sort(a[2].begin(), a[2].end());
    sort(a[3].begin(), a[3].end());
    sort(a[4].begin(), a[4].end());

    int s1=a[1].size();
    int s2=a[2].size();
    int s3=a[3].size();
    int s4=a[4].size();

    int ans=0;
    for(int x: a[1]) ans-=x;

    int m = min(s2, s3);

    vector<int> rem;

    for(int i=0; i<m; i++) ans-=a[2][i];
    for(int i=m; i<s2; i++) rem.push_back(a[2][i]);

    for(int i=0; i<m; i++) ans-=a[3][i];
    for(int i=m; i<s3; i++) rem.push_back(a[3][i]);

    for(int i=0; i<s4; i++) rem.push_back(a[4][i]);

    sort(rem.begin(), rem.end());
    int k = rem.size();
    k = min(k, s1);

    for(int i=0; i<k; i++) ans-=rem[i];
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}