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
int n,a[1001],s1,s2;
void solve(){
    cin>>n;
    rep(i,0,n/2){
        cin>>a[i];
    }
    sort(a,a+n/2);
    rep(i,0,n/2){
        s1+=abs(a[i]-(2*i+1));
        s2+=abs(a[i]-(2*i+2));
    }
    cout<<min(s1,s2)<<endl;
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