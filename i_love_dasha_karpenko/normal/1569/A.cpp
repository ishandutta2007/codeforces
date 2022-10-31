#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 57;
int A[N],dp[N][N];
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 1;i<n;++i){
        if (s[i]!=s[i-1]){
            cout<<i<<' '<<i+1<<endl;
            return;
        }
    }
    cout<<"-1 -1\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}