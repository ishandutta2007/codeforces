#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2E5+7;
ll dp[N];
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    if (n-m+k<0){
        cout<<0<<'\n';
        return;
    }
    ld P = 1.0;
    int ptr1 = m,ptr2 = n+k+1;
    int lim1 = m-k,lim2 = n+1;
    while(ptr1>=lim1 || ptr2>=lim2){
        if (ptr1<lim1 || P>1){
            P = P/ptr2;
            --ptr2;
        }
        else if (ptr2<lim2){
            P = P*ptr1;
            --ptr1;
        }
        else if (P>1.0){
            P = P/ptr2;
            --ptr2;
        }
        else{
            P = P*ptr1;
            --ptr1;
        }
    }
    cout<<fixed<<setprecision(10)<<1.0-P<<'\n';
}
int main() {
    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}