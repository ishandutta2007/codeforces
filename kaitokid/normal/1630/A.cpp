#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[2000000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++)vis[i]=0;

    if(n==4 && k==3){cout<<-1<<endl;continue;}

    if(k==n-1)
    {
    vector<pair<int,int> >ans;
    int m=n-1;
    for(int i=4;i<n-2;i++)
    {
        if(i==3 || (m^i)==3)continue;
        if(vis[i])continue;
        ans.push_back({i,m^i});
        vis[i]=vis[m^i]=1;
    }
       for(int i=0;i<ans.size();i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
   cout<<m<<" "<<m-1<<endl;
   cout<<1<<" "<<3<<endl;
   cout<<0<<" "<<(m^3)<<endl;
   continue;
    }
    vector<pair<int,int> >ans;
    int m=n-1;
    for(int i=1;i<n-1;i++)
    {
        if(i==k || (m^i)==k)continue;
        if(vis[i])continue;
        ans.push_back({i,m^i});
        vis[i]=vis[m^i]=1;
    }

    for(int i=0;i<ans.size();i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
    if(k==0){cout<<0<<" "<<m<<endl;continue;}
    if(k!=m){
    cout<<k<<" "<<m<<endl;
    cout<<0<<" "<<(m^k)<<endl;
    }
    }

    return 0;
}