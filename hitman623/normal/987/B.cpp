#include <bits/stdc++.h>

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
double x,y;
void solve(){
    cin>>x>>y;
    if(x<=5 and y<=5){
        int a=1,b=1;
        rep(i,0,y){
            a*=x;
        }
        rep(i,0,x){
            b*=y;
        }
        if(a<b) cout<<"<"<<endl;
        else if(a==b) cout<<"="<<endl;
        else cout<<">"<<endl;
        return;
    }
    if(x==y){
        cout<<"="<<endl;
        return;
    }
    if(1.0l*y*log(x)>1.0l*x*log(y)){
        cout<<">"<<endl;
    }
    else{
        cout<<"<"<<endl;
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