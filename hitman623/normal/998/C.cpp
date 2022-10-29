#include <bits/stdc++.h>

#define int         long long
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
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,x,y,z,o;
string s,a;
void solve(){
    cin>>n>>x>>y;
    cin>>s;
    rep(i,0,n){
        if(i==0 || s[i]!=s[i-1]){
            a+=s[i];
        }
    }
    n=sz(a);
    rep(i,0,n){
        if(a[i]=='0') z++;
        else o++;
    }
    o-=a[0]=='1';
    o-=a.back()=='1';
    o=max(0LL,o);
    cout<<min(o*x+y,z*y)<<endl;
}
//0101010101
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