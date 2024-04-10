#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e5+7;
int A[N],B[N];
void solve(){
    int n,x;
    cin>>n>>x;
    for(int i = 1;i<=n;++i)
        cin>>A[i],B[i] = A[i];
    sort(B+1,B+1+n);
    int l = n-x+1,r = x;
    for(int i = l;i<=r;++i){
        if (A[i]!=B[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}