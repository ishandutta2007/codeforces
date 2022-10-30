#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'a'+1)

void solve() {
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 1;i<=n;++i){
        int val;
        cin>>val;
        sum+=val;
    }
    if (sum%n==0)
        cout<<"0\n";
    else
        cout<<"1\n";
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}