#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 2E5+7;
int A[DIM];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    int prev = 0;
    for(int i = 1;i<=n;++i){
        int cur = 0;
        for(int bit = 0;bit<30;++bit){
            if ((prev&(1<<bit)) && !(A[i]&(1<<bit)))
                cur^=(1<<bit);
        }
        cout<<cur<<' ';
        prev = A[i]^cur;
    }
    cout<<endl;
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