#include <bits/stdc++.h>
#define int         long long
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi             map<int,int>
#define mii            map<int,pii>    
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)    for(int i=a;i<b;i++)
using namespace std;
pii cal(ll m){
    if(m<8) return {m,m};
    ll h=pow(m,1.0/3);
    if((h+1)*(h+1)*(h+1)<=m) h++;
    auto p1=cal(m-h*h*h);
    auto p2=cal(h*h*h-(h-1)*(h-1)*(h-1)-1);
    p1.x+=1,p2.x+=1;
    p1.y+=(h*h*h);
    p2.y+=(h-1)*(h-1)*(h-1);
    return max(p1,p2);
}
void solve()
{
    ll m;
    cin>>m;
    auto temp=cal(m);
    cout<<temp.x<<" "<<temp.y<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)
        solve();
    return 0;
}