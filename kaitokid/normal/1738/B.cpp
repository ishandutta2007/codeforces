#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100009];
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
        for(int i=0;i<k;i++)cin>>a[i];
        if(k==1){cout<<"Yes"<<endl;continue;}
        vector<ll>g;
        for(int i=1;i<k;i++)g.push_back(a[i]-a[i-1]);
        bool bl=true;
        for(int i=1;i<g.size();i++)if(g[i]<g[i-1])bl=false;
        if(!bl){cout<<"No"<<endl;continue;}
        ll r=g[0]*(n-k+1);
        if(r<a[0])cout<<"No"<<endl;
          else cout<<"Yes"<<endl;

    }
    return 0;
}