#include <bits/stdc++.h>

#define ll          long long
#define pb          emplace_back
#define pii         pair<int,int>
#define tiii        tuple<int,int,int>
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
int n,q,p[100005];
vi basis[100005];
void solve(){
    cin>>n>>q;
    p[0]=1;
    rep(i,0,n){
        p[i+1]=2*p[i]%hell;
        int x;
        cin>>x;
        if(i){
            basis[i]=basis[i-1];
        }
        for(auto j:basis[i]){
            x=min(x,x^j);
        }
        if(x){
            basis[i].pb(x);
        }
    }
    while(q--){
        int l,x;
        cin>>l>>x;
        for(auto j:basis[l-1]){
            x=min(x,j^x);
        }
        if(x==0){
            cout<<p[l-sz(basis[l-1])]<<endl;
        }
        else{
            cout<<0<<endl;
        }
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