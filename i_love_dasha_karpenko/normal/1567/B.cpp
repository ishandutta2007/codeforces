//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gt(tuple,el) (get<el>(tuple))
const int N = 3e5+7;
int dp[N];
void solve(){
    int a,b;
    cin>>a>>b;
    int need = dp[a-1]^b;
    if (need==0){
        cout<<a<<endl;
        return;
    }
    if (need==a){
        cout<<a+2<<endl;
        return;
    }
    cout<<a+1<<endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for(int i = 1;i<N;++i){
        dp[i] = dp[i-1]^i;
    }
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}