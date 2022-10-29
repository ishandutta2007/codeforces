#include <bits/stdc++.h>
#define int         long long
#define x           first
#define y           second
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define pb          push_back
#define all(a)      (a).begin(),(a).end()
using namespace std;
int n,m,r,k;
vector<int> row,col;
set<pair<int,pair<int,int>>> s;
map<pair<int,int>,int> mp;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>r>>k;
    rep(i,1,n+1)    
    row.pb(min({r,i,n-r+1-max(0LL,i-r)}));
    rep(i,1,m+1)
    col.pb(min({r,i,m-r+1-max(0LL,i-r)}));
    sort(all(row),greater<int>());
    sort(all(col),greater<int>());
    double ans=0,den=(n-r+1)*(m-r+1),cur=0;
    s.insert({row[0]*col[0],{0,0}});
    rep(i,0,k){
        auto d=*s.rbegin();
        int val=d.x,L=d.y.x,R=d.y.y;
        ans+=val;
        mp[{L,R}]=1;
        s.erase(d);
        if(R<m-1 && mp[{L,R+1}]==0)
            s.insert({row[L]*col[R+1],{L,R+1}});
        if(L<n-1 && mp[{L+1,R}]==0)
            s.insert({row[L+1]*col[R],{L+1,R}});
    }
    cout<<fixed<<setprecision(10)<<ans/den;
    return 0;
}