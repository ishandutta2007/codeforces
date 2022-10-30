#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'
const int N = 5007;
int A[N],T[N];
void add(int pos,int delta){
    for(int i = pos;i<N;i+=i&-i){
        T[i] += delta;
    }
}
int get(int pos){
    int ret = 0;
    for(int i = pos;i>0;i-=i&-i){
        ret += T[i];
    }
    return ret;
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
    }
    ll res = 0;
    for(int i = 1;i<=n;i+=1){
        ll cnt = 0;
        for(int j = n;j>i;--j){
            ll clk = get(A[j]);
            res += clk*cnt;
            cnt += A[i]>A[j];
        }
        add(A[i],1);
    }
    for(int i = 1;i<=n;++i){
        add(A[i],-1);
    }
    cout<<res<<endl;
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