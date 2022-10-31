#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
const int INF = 1e9+7;
const int N = 1e5+7;
#define int ll
int A[N];
void solve() {
    ll n;
    cin>>n;
    if (n<=2){
        cout<<"-1\n";
    }
    else{
        int pr = 2;
        while(n%pr==0)
            pr*=2;
        int x = (2*n/pr-pr+1);
        if (x%2 || x<=0) {
            pr = n/(pr/2);
            ll x = round(ld(n)/pr-ld(pr)/2+ld(1)/2);

            if (pr>1 && x*pr + (pr-1)*pr/2 == n && x>0)
                cout<<pr<<endl;
            else cout<<"-1\n";
        }
        else
        cout<<pr<<endl;
    }

}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}