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
#define N           100000
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,ans,f[1001];
void solve(){
    cin>>n;
    if(n%2){
        cout<<(n/2+1)*(n/2+1)<<endl;
    }
    else{
        cout<<(n/2)*(n/2+1)<<endl;
    }
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