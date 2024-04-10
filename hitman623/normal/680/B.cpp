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
    int n,a,t[101],d[101]={0},ans=0;
    cin>>n>>a;
    rep(i,1,n+1){
        cin>>t[i];
        if(t[i])
        d[abs(i-a)]++;
    }
    if(d[0]) ans++;
    int temp=min(a,n-a+1);
    rep(i,1,temp){
        if(d[i]==2) ans+=2;
    }
    rep(i,temp,n){
        if(d[i]==1) ans++;
    }
    cout<<ans;
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