#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 2e5+7;
const ll INF = 1e18;
ll A[N];
void solve() {
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    sort(A+1,A+1+n);
    ll sum_neg = 0,sum_pos = 0;
    for(int i = 1;i<=n;++i){
        sum_pos+=A[i];
    }
    if ((sum_pos-A[1])+A[1]*(n-1)>0 || (sum_pos-A[n])+A[n]*(n-1)<0){
        cout<<"INF\n";
        return;
    }
    int ptr = 1;
    const int LIM  = 1e6;
    ll res = -INF;
    A[0] = -1e7,A[n+1] = 1e7;
    bool flag = 0;
    for(ll ptr = 1;ptr<=n+1;++ptr){
        ll l = -A[ptr-1]-1,r = -A[ptr];
        if (r<=l)
            for(ll i:{l,r})
                if (ptr==1){
                    res = max(res,(sum_pos-A[1]+i*(n-1))*(A[1]+i)-i*i*(n-1));
                }
                else if (ptr>n){
                    res = max(res,(sum_neg-A[n]+i*(n-1))*(A[n]+i)-i*i*(n-1));
                }
                else{
                    res = max(res,(sum_neg+i*(ptr-1))*(A[n]+i)+(sum_pos+(n-ptr+1)*i)*(A[1]+i)-(A[n]+i)*(A[1]+i)-i*i*(n-1));
                }
        sum_pos-=A[ptr];
        sum_neg+=A[ptr];
    }
    cout<<res<<endl;
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}