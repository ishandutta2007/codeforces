#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MOD = 998244353;
const int N = 2e5+7;
int A[N];
void solve(){
    int n;
    cin>>n;
    pair<int,int> mx;
    for(int i = 1;i<=n;++i){
        int x;
        cin>>x;
        A[i] = x;
        mx.second = max(mx.second,x);
        if (mx.first<mx.second)
            swap(mx.first,mx.second);
    }
    if (mx.first>=mx.second+2){
        cout<<"0\n";
        return;
    }
    if (mx.first==mx.second+1){
        int cnt = 0,cnt1 = 0;
        for(int i = 1;i<=n;++i){
            cnt+=(A[i]==mx.second);
            cnt1+=(A[i]==mx.first);
        }
        ll res = 1;
        for(int i = 1;i<=cnt;++i){
            res = (res*i)%MOD;
        }
        res = (res*cnt1)%MOD;
        int gap = cnt+1;
        for(int i = 2;i<=cnt1;++i){
            res = (res*gap)%MOD;
            ++gap;
        }
        ++gap;
        for(int i = cnt1+cnt+1;i<=n;++i){
            res = (res*gap)%MOD;
            ++gap;
        }
        ll r = 1;
        for(int i = 1;i<=n;++i){
            r = (r*i)%MOD;
        }
        res = (r-res)%MOD;
        if (res<0)
            res+=MOD;
        cout<<res<<endl;
    }
    else{
        ll res = 1;
        for(int i = 1;i<=n;++i){
            res = (res*i)%MOD;
        }
        cout<<res<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}