//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
//#define endl '\n'
#define all(var) var.begin(),var.end()
#define gi(x) int(x-'0')
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;

ll ask(int l,int r){
    cout<<"? "<<l<<' '<<r<<endl;
    ll ret;
    cin>>ret;
    return ret;
}
void solve(){
    int n;
    cin>>n;
    int l = 1,r = n;
    while(l!=r){
        int tm = (l+r+1)>>1;
        if (ask(1,tm)==0)
            l = tm;
        else r = tm-1;
    }
    ll total = ask(1,n);
    ll left_cnt = total-ask(l+1,n)+1;
    ll rpos = l+left_cnt;
    ll right_cnt = ask(rpos,n)-ask(rpos+1,n)+1;
    cout<<"! "<<l<<' '<<l+left_cnt<<' '<<l+left_cnt+right_cnt-1<<endl;

}
signed main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}