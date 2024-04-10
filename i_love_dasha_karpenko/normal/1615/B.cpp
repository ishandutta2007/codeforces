#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'a'+1)

int cnt(int n,int bit){
    int full = (n+1)/bit;
    int ret = (full>>1)*bit;
    if (full&1)
        ret+=(n+1)%bit;
    return n-ret;
}

void solve() {
    int l,r;
    cin>>l>>r;
    int res = r-l+1;
    for(int bit = 0;(1<<bit)<=r;++bit){
        res = min(res,cnt(r,1<<bit)-cnt(l-1,1<<bit));
    }
    cout<<res<<endl;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}