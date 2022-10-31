#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 1E5+7;
int A[DIM];
int cnt[2][DIM];
int solve() {
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        ++cnt[i%2][A[i]];
    }
    sort(A+1,A+1+n);
    int flag = 0;
    for(int i = 1;i<=n;++i){
        cnt[i%2][A[i]]--;
    }
    for(int i = 1;i<=n;++i){
        if (cnt[0][A[i]] || cnt[1][A[i]])
            flag = 1;
        cnt[0][A[i]] = cnt[1][A[i]] = 0;
    }
    if (flag)
        cout<<"NO\n";
    else cout<<"YES\n";

    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        assert(solve());
}