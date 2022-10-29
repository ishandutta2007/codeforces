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
int n,p[1000006],v[1000006],s;
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>p[i];
    }
    rep(i,1,n+1){
        if(v[i]) continue;
        int cnt=0;
        while(!v[i]){
            v[i]=1;
            i=p[i];
            cnt++;
        }
        s+=cnt-1;
    }
    if(n%2){
        if(s%2){
            cout<<"Petr"<<endl;
        }
        else{
            cout<<"Um_nik"<<endl;
        }
    }
    else{
        if(s%2){
            cout<<"Um_nik"<<endl;
        }
        else{
            cout<<"Petr"<<endl;
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