//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void solve(){
    int n;
    cin>>n;
    int res = 0;
    while(n){
        res = max(res,n%10);
        n/=10;
    }
    cout<<res<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int t;
    //t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}