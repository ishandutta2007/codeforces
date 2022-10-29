#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          unordered_map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m;
bitset<2000> b[2001];
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        string s;
        cin>>s;
        rep(j,0,m){
            if(s[j]=='1'){
                b[i].set(j);
            }
        }
    }
    rep(i,0,n){
        bitset<2000> cur;
        cur.reset();
        rep(j,0,n){
            if(i==j) continue;
            cur|=b[j];
        }
        if(cur.count()==m){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}