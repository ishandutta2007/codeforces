#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 5007;
int A[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    ll ans = 1e18;
    for(int mid = 1;mid<=n;++mid){
        ll res = 0;
        ll prev = 0;
        for(int i = mid-1;i>=1;--i){
            ++prev;
            if (A[i]<prev){
                ll g = prev/A[i] + (prev%A[i]!=0);
                res+=g;
                prev = g*A[i];
            }
            else{
                prev = A[i];
                ++res;
            }

        }
        prev = 0;
        for(int i = mid+1;i<=n;++i){
            ++prev;
            if (A[i]<prev){
                ll g = prev/A[i] + (prev%A[i]!=0);
                res+=g;
                prev = g*A[i];
            }
            else{
                prev = A[i];
                ++res;
            }
        }
        ans = min(ans,res);
    }
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}