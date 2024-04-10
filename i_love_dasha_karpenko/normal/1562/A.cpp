#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int l,r;
    cin>>l>>r;
    int div = max(r/2+1,l);
    cout<<r%div<<endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}