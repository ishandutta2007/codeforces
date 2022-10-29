#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,s[3003],c[3003],ans=hell;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>s[i];
    }
    rep(i,0,n){
        cin>>c[i];
    }
    rep(i,1,n-1){
        int c1=hell,c2=c[i],c3=hell;
        rep(j,0,i){
            if(s[j]<s[i]){
                c1=min(c1,c[j]);
            }
        }
        rep(j,i+1,n){
            if(s[j]>s[i]){
                c3=min(c3,c[j]);
            }
        }
        if(c1<hell and c3<hell){
            ans=min(ans,c1+c2+c3);
        }
    }
    if(ans<hell){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}