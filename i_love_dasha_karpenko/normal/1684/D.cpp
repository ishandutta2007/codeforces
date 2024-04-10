#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
int A[N];
void solve(){
    int n,k;
    cin>>n>>k;
    ll res = 0;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
        res += A[i];
        A[i] = n-i-A[i];
    }
    sort(A+1,A+1+n);
    for(int i = 1;i<=k;i+=1){
        res += A[i];
    }
    cout<<res - ll(k)*(k-1)/2<<endl;

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}