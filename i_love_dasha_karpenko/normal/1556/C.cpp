#pragma GCC Optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e3+7;
ll A[N];
void solve(){
    ll n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];

    }
    ll res = 0;
    for(int i = 1;i<=n;i+=2){
        ll mi = 0,cur = 0;
        for(int j = i+1;j<=n;j+=2){
            ll inter = mi;
            ll v1 = A[i],v2 = A[j],cr = cur,flag1 = 0,flag2 = 0;
            if (inter<0){
                v1-=abs(inter);
                cr+=abs(inter);
                flag1 = 1;
            }
            if (cr>0){
                v2-=cr;
                flag2 = 1;
            }
            res+=max(0ll,min(v1,v2));
            if (v1>=0 && v2>=0 && flag1 && flag2){
                ++res;
            }
            mi = min(mi,cur-A[j]);
            cur-=A[j];
            cur+=A[j+1];
        }
    }
    cout<<res<<endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    //cin>>t;
    t = 1;
    while(t--)
        solve();
    return 0;
}