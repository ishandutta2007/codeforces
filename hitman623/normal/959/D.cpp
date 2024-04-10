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
int n,a[100005],b[100005],vis[1500007];
set<int> source;
void solve(){
    cin>>n;
    rep(i,2,1500007){
        source.insert(i);
    }
    rep(i,0,n){
        cin>>a[i];
    }
    set<int> s;
    int f=0;
    rep(i,0,n){
        vi primes;
        if(f) b[i]=*source.begin();
        else{
            if(a[i]==1){
                b[i]=*source.lower_bound(a[i]+1);
            }
            else{
                b[i]=*source.lower_bound(a[i]);
            }
        }
        if(b[i]>a[i]) f=1;
        int cur=b[i];
        for(int j=2;j*j<=cur;++j){
            if(cur%j==0){
                primes.pb(j);
                while(cur%j==0) cur/=j;
            }
        }
        if(cur>1) primes.pb(cur);
        for(auto j:primes){
            if(vis[j]) continue;
            vis[j]=1;
            for(int k=j;k<=1500000;k+=j){
                if(source.find(k)!=source.end()){
                    source.erase(source.find(k));
                }
            }
        }
    }
    rep(i,0,n){
        cout<<b[i]<<" ";
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