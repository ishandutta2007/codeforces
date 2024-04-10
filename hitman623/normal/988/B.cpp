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
int n;
string s[1001];
bool is(string a,string b){
    rep(i,0,sz(b)){
        int f=1;
        if(i+sz(a)>sz(b)) return 0;
        rep(j,0,sz(a)){
            if(b[i+j]!=a[j]){
                f=0;
            }
        }
        if(f) return 1;
    }
    return 0;
}
bool cmp(string a,string b){
    return sz(a)<sz(b);
}
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>s[i];
    }
    sort(s,s+n,cmp);
    rep(i,0,n-1){
        if(!is(s[i],s[i+1])){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    rep(i,0,n){
        cout<<s[i]<<endl;
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