//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 107;
int A[N],B[N];
void solve(){
    int n;
    cin>>n;
    ll res = 0;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        int num = ch-'0';
        if (num==0)
            continue;
        res+=num+(i!=n);
    }
    cout<<res<<endl;



}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}