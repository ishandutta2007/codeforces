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
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[11],S;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        S+=a[i];
    }
    rep(i,0,1<<n){
        int s=0;
        rep(j,0,n){
            if((i>>j)&1){
                s+=a[j];
            }
        }
        if(s!=S-s){
            int d=__builtin_popcount(i);
            if(d!=n and d!=0){
                cout<<d<<endl;
                rep(j,0,n){
                    if((i>>j)&1){
                        cout<<j+1<<" ";
                    }
                }
                return ;
            }
        }
    }
    cout<<-1<<endl;
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