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
string s;
int ans=hell;
void solve(){
    cin>>s;
    int n=sz(s);
    rep(i,0,1<<n){
        string temp;
        int cnt=0;
        rep(j,0,n){
            if((i>>j)&1){
                temp+=s[j];
            }
            else cnt++;
        }
        if(temp[0]=='0') continue;
        int cur=0;
        rep(j,0,sz(temp)){
            cur=cur*10+temp[j]-'0';
        }
        int d=sqrt(cur);
        if(d*d==cur){
            ans=min(ans,cnt);
        }
    }
    if(ans==n){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
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