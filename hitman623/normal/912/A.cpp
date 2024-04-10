#include <bits/stdc++.h>

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

void solve()
{
    ll a,b,x,y,z;
    cin>>a>>b>>x>>y>>z;
    cout<<max(0LL,2*x+y-a)+max(0LL,y+3*z-b);   
}

int main()
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