#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
const int N = 77;
const int MXN = 200;
int A[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        A[i] = A[i]<<1;
    }
    if (n==1){
        cout<<"0\n";
        return;
    }
    int res = n;
    for(int i = 1;i<=n;++i){
        for(int j = i+1;j<=n;++j){
            int r = 0;
            for(int k = 1;k<=n;++k){
                if (A[k]*(j-i)==(A[j]-A[i])*(k-i)+A[i]*(j-i))
                    ++r;
            }
            res = min(res,n-r);
        }
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}