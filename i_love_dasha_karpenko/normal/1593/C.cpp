
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 4e5+7;
int A[N];
int n,k;
bool F(int num){
    int cat = 0;
    for(int i = k-num+1;i<=k;++i){
        if (cat>=A[i])
            return false;
        cat+=(n-A[i]);
    }
    return true;
}
void solve(){

    cin>>n>>k;
    for(int i = 1;i<=k;++i)
        cin>>A[i];
    sort(A+1,A+1+k);
    int l = 0,r = k;
    while(l<r){
        int tm = (l+r+1)>>1;
        if (F(tm))
            l = tm;
        else r = tm-1;
    }
    assert(l==r);
    cout<<l<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();


    return 0;
}