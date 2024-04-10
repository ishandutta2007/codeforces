#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')


void solve() {
   // cout<<endl;
    int n,k;
    cin>>n>>k;
    if ((k<<1)-1>n){
        cout<<"-1\n";
        return;
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            if (i==j && (i&1) && ((i+1)>>1)<=k){
                cout<<'R';
            }
            else cout<<'.';
        }
        cout<<endl;
    }

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}