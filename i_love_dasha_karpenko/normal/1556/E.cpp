#pragma GCC Optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
ll A[N];
struct tnode {
    ll first,second, mx;
} T[N*4];
tnode merge(tnode l,tnode r){
    tnode ret;
    ret.first = l.first+r.first;
    ret.second = min(l.second,r.second+l.first);
    ret.mx = max(l.mx,r.mx+l.first);
    return ret;
}
void buildtree(int t,int tl,int tr){
    if (tl==tr){
        T[t] = {A[tl],A[tl],max(0ll,A[tl])};
        return;
    }
    int tm = (tl+tr)>>1;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = merge(T[t*2+1],T[t*2+2]);
}
tnode get(int t,int tl,int tr,int l,int r){
    if (l>tr || tl>r)
        return {0,0,0};
    if (l<=tl && tr<=r)
        return T[t];
    int tm = (tl+tr)>>1;
    return merge(get(t*2+1,tl,tm,l,r),get(t*2+2,tm+1,tr,l,r));
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    for(int i = 1;i<=n;++i){
        ll x;
        cin>>x;
        A[i] = x-A[i];
    }
    buildtree(0,1,n);
    while(q--){
        int l,r;
        cin>>l>>r;
        tnode ret = get(0,1,n,l,r);
        if (ret.first==0 && ret.second==0)
            cout<<ret.mx<<endl;
        else cout<<"-1\n";
    }

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