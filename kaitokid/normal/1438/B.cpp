#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<int,bool>mp;
int main()
{    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t;
cin>>t;
while(t--)
{
    mp.clear();
    bool ans=false;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(mp[x])ans=true;
        mp[x]=true;
    }
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";
}
    return 0;
}