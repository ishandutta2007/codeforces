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
int n,q,ans=0;
void solve()
{
    cin>>n;
    vi a(n);
    rep(i,0,n)
        cin>>a[i];
    rep(i,0,n)
        rep(j,i+1,n)
            ans^=(a[i]>a[j]);            
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        ans^=((r-l+1)*(r-l)/2)&1;
        if(ans) cout<<"odd";
        else cout<<"even";
        cout<<endl;
    }
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