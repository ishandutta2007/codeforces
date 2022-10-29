#include <bits/stdc++.h>

#define int         unsigned long long
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
int n,p,q,b;
void solve(){
    cin>>n;
    while(n--){
        cin>>p>>q>>b;
        int g=__gcd(p,q);
        p/=g;
        q/=g;
        rep(i,0,62){
            int w=__gcd(q,b);
            if(q==1 || b==1 || w==1) break;
            while(q%w==0){
                q/=w;
            }
            if(q==1 || b==1 || w==1) break;
        }
        if(q==1) cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
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