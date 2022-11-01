
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const int N=300010;
int x[N],t[N];
int n;
bool ok(int d){
    int L=-1e9;
    int R=1e9;
    for (int i=1;i<=n;i++){
        if (d<t[i]) return false;
        int l=x[i]-(d-t[i]);
        int r=x[i]+(d-t[i]);
        L=max(L,l);
        R=min(R,r);
        if (L>R) return false;
    }
    return true;
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x[i];
        x[i]*=2;
    }
    for (int i=1;i<=n;i++){
        cin>>t[i];
        t[i]*=2;
    }
    if (ok(0)){
        cout<<x[1]<<'\n';
        return;
    }
    int L=0,R=1e9;
    while (R-L>1){
        int mid=(L+R)/2;
        if (ok(mid)) R=mid;
        else L=mid;
    }
    int d=R;
    L=-1e9;
    R=1e9;
    for (int i=1;i<=n;i++){
        int l=x[i]-(d-t[i]);
        int r=x[i]+(d-t[i]);
        L=max(L,l);
        R=min(R,r);
    }
    cout<<setprecision(10)<<fixed<<L/2.0<<'\n';


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}