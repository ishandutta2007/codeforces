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
int n;
int f(int n){
    set<int> s;
    rep(j,0,n+1){
        rep(k,0,n+1){
            rep(l,0,n+1){
                rep(m,0,n+1){
                    if(j+k+l+m==n){
                        s.insert(j+5*k+10*l+50*m);
                    }
                }
            }
        }
    }
    return sz(s);
}
void solve(){
    cin>>n;
    if(n<=20){
        cout<<f(n)<<endl;
    }
    else cout<<f(20)+(n-20)*49<<endl;
}
//a+b+c+d=n
//a+5*b+10*c+50*d//

//(1+yx+y^2*x^2+..)(1+y*x^5+y^2*x^10)
//___________1____________________//
//(1-yx)(1-yx^5)(1-yx^10)(1-yx^50)
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