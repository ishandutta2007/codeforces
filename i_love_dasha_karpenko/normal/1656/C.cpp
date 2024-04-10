#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
const int INF = 1e9+7;
const int N = 1e5+7;
int A[N];
void solve() {
    int n;
    cin>>n;
    bool flag = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        if (A[i]==1)
            flag = 1;
    }
    if (!flag)
        cout<<"YES\n";
    else{
        sort(A+1,A+1+n);
        for(int i = 1;i<n;++i)
            if (A[i]+1==A[i+1]){
                cout<<"NO\n";
                return;
            }
        cout<<"YES\n";
    }

}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}