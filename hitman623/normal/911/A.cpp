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
    int n,m=hell;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
        m=min(m,a[i]);
    }
    int cur=-1,ans=hell;
    rep(i,0,n)
        if(a[i]==m)
        {
            if(cur!=-1)
            ans=min(ans,i-cur);
            cur=i;
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