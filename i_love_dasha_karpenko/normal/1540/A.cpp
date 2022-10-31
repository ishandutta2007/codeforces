#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long big;
const int DIM = 1E5+7;
big A[DIM];
void solve(){

    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    sort(A+1,A+1+n);
    big res = 0;
    big sum = 0;
    for(int i = 3;i<=n;++i){
        res-=A[i]*(i-2)-sum;
        sum+=A[i-1];
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}