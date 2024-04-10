#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
const int N = 2e5+7;
int A[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
    }
    ll cnt = 0;
    for(int i = 1;i<=n;i+=1){
        if (A[i]>0){
            if (cnt==0 && i!=1){
                cout<<"No\n";
                return;
            }
            cnt += A[i];
        }
        else{
            cnt += A[i];
        }
        if (cnt<0){
            cout<<"No\n";
            return;
        }
    }
    if (cnt!=0){
        cout<<"No\n";
        return;
    }

    cout<<"Yes\n";
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}