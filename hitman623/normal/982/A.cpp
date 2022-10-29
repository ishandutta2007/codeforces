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
int n,cnt;
string s;
void solve(){
    cin>>n>>s;
    if(n==1){
        if(s=="1") cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return;
    }
    if(s[0]=='0' and s[1]=='0'){
        cout<<"No"<<endl;
        return;
    }
    if(s[n-1]=='0' and s[n-2]=='0'){
        cout<<"No"<<endl;
        return;
    }
    if(n==2){
        if(s=="00" || s=="11") cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        return;
    }
    rep(i,0,n-1){
        if(s[i]==s[i+1] and s[i]=='1'){
            cout<<"No"<<endl;
            return;
        }
    }
    rep(i,0,n-2){
        if(s[i]==s[i+1] and s[i+1]==s[i+2] and s[i]=='0'){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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