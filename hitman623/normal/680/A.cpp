#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<int,pii>    
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

void solve()
{
    int a[5],s=0,ans=hell;
    rep(i,0,5)
    cin>>a[i],s+=a[i];
    sort(a,a+5);
    ans=s;
    rep(i,0,5){
        if(i+1>=5) continue;
        if(a[i]==a[i+1]){
            ans=min(ans,s-a[i]-a[i+1]);
        }
    }      
    rep(i,0,5){
        if(i+2>=5) continue;
        if(a[i]==a[i+1] && a[i+1]==a[i+2]){
            ans=min(ans,s-a[i]-a[i+1]-a[i+2]);
        }
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