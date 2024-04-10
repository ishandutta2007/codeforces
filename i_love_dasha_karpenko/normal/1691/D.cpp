#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll INF = 1e18+7;
const int N = 2e5+7;
struct tnode{
    ll lsum,rsum,sum,mxsum;
} T[N*2];
pair<int,int> A[N];
tnode merge(tnode a,tnode b){
    a.mxsum = max({a.mxsum,a.rsum+b.lsum});
    a.rsum = max(a.rsum+b.sum,b.rsum);
    a.lsum = max(a.lsum,b.lsum+a.sum);
    a.sum += b.sum;
    a.mxsum = max({a.mxsum,b.mxsum,a.lsum,a.rsum});

    a.sum = max(a.sum,-INF);
    a.rsum = max(a.rsum,-INF);
    a.lsum = max(a.lsum,-INF);
    a.mxsum = max(a.mxsum,-INF);
    return a;
}
void buildtree(int t,int tl,int tr){
    if (tl==tr){
        T[t] = {0,0,-INF,-INF};
        return;
    }
    int tm = (tl+tr)/2;
    buildtree(t+1,tl,tm);
    buildtree(t+(tm-tl+1)*2,tm+1,tr);
    T[t] = merge(T[t+1],T[t+(tm-tl+1)*2]);
}
void update(int t,int tl,int tr,int pos,ll val){
    if (tl>pos || tr<pos){
        return;
    }
    if (tl==tr){
        T[t] = {max(0ll,val),max(0ll,val),val,max(0ll,val)};
        return;
    }
    int tm = (tl+tr)/2;
    update(t+1,tl,tm,pos,val);
    update(t+(tm-tl+1)*2,tm+1,tr,pos,val);
    T[t] = merge(T[t+1],T[t+(tm-tl+1)*2]);
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i].first;
        A[i].second = i;
    }
    sort(A+1,A+1+n);
    buildtree(0,1,n);
    for(int i = 1;i<=n;i+=1){
        update(0,1,n,A[i].second,A[i].first);
        if (T[0].mxsum>A[i].first && A[i].first>=0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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