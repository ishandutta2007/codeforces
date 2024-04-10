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

void solve(){
    int n;
    cin>>n;
    if(n<=5){
        cout<<-1<<endl;
    }
    else if(n==6){
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<3<<endl;
        cout<<1<<" "<<4<<endl;
        cout<<2<<" "<<5<<endl;
        cout<<2<<" "<<6<<endl;
    }
    else if(n==7){
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<3<<endl;
        cout<<1<<" "<<4<<endl;
        cout<<2<<" "<<5<<endl;
        cout<<2<<" "<<6<<endl;
        cout<<2<<" "<<7<<endl;
    }
    else{
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<3<<endl;
        cout<<3<<" "<<6<<endl;
        cout<<2<<" "<<4<<endl;
        cout<<2<<" "<<5<<endl;
        rep(i,7,n+1){
            cout<<4<<" "<<i<<endl;
        }
    }
    rep(i,1,n){
        cout<<i<<" "<<i+1<<endl;
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