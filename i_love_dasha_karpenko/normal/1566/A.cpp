#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 3e5+7;

void solve(){
    int n,s;
    cin>>n>>s;
    int pos = (n>>1)+(n&1);
    int cnt = n-pos+1;
    cout<<s/cnt<<endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}