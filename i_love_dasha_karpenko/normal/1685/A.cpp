#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
int A[N],B[N];
bool Check(int n){
    for(int i = 0;i<n;i+=1){
        if (!(B[i+1]<B[(i+1)%n+1] && B[i+1]<B[(i+n-1)%n+1]) && !(B[i+1]>B[(i+1)%n+1] && B[i+1]>B[(i+n-1)%n+1])){
            return 0;
        }
    }
    return 1;
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
    }
    sort(A+1,A+1+n);
    int ptr = 1;
    for(int i = 1;i<=n;i+=2){
        B[i] = A[ptr++];
    }
    for(int i = 2;i<=n;i+=2){
        B[i] = A[ptr++];
    }
    if (Check(n)){
        cout<<"YES\n";
        for(int i = 1;i<=n;i+=1){
            cout<<B[i]<<' ';
        }
        cout<<endl;
        return;
    }
    cout<<"NO\n";
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