#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 4E5+7;
const int INF = 2E9;
int A[DIM],T[DIM*4];
void buildtree(int t,int tl,int tr){
    if (tl==tr){
        T[t] = A[tl];
        return;
    }
    int tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = __gcd(T[t*2+1],T[t*2+2]);
}
int query(int t,int tl,int tr,int l,int r,int &cur,int need){
    if (tl>r || l>tr)
        return tr+1;
    if (l<=tl && tr<=r && __gcd(T[t],cur)!=need) {
        cur = __gcd(cur,T[t]);
        return tr + 1;
    }
    if (tl==tr) {
        cur = __gcd(cur,T[t]);
        return tl;
    }
    int tm = (tl+tr)/2;
    int ret = query(t*2+1,tl,tm,l,r,cur,need);
    if (ret==tm+1)
        ret = query(t*2+2,tm+1,tr,l,r,cur,need);
    return ret;
}
void solve(){
    int n;
    cin>>n;
    int g = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        g = __gcd(g,A[i]);
        A[i+n] = A[i];
    }
    buildtree(0,1,n*2);
    int res = 0;
    for(int i = 1;i<=n;++i){
        int x = A[i];
        res = max(res,query(0,1,n*2,i,n*2,x,g)-i);
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}