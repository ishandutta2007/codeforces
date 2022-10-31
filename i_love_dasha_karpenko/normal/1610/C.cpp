//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;
const int N = 2e5+7;
pair<int,int> A[N];
void solve(){
    int n;
    cin>>n;

    for(int i = 1;i<=n;++i){
        cin>>A[i].first>>A[i].second;
    }
    int l = 0,r = n;
    while(l!=r){
        int tm = (l+r+1)>>1;
        int ptr = 0;
        for(int i = 1;i<=n;++i){
            if (A[i].second>=ptr && tm-ptr-1<=A[i].first)
                ++ptr;
            ptr = min(ptr,tm);
        }
        if (ptr==tm)
            l = tm;
        else r = tm-1;
    }
    cout<<l<<endl;

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}