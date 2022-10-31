//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
int A[N],B[N],M[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    for(int i = 1;i<=n;++i) {
        cin >> B[i];
        M[i] = max(M[i-1], B[i]);
    }
    int ptr = 1;
    while(B[ptr]<A[1])
        ++ptr;
    if (ptr==1){
        cout<<"0\n";
        return;
    }
    int res = n;
    int mv = A[1];
    for(int i = 1;i<=n;++i){
        if (A[i]>mv)
            continue;
        mv = A[i];
        while(ptr>1 && M[ptr-1]>A[i])
            --ptr;
        res = min(res,i-1+ptr-1);
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