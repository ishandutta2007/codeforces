//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int DIM = 2E5+7;
ll T[DIM*4],A[DIM];
void buildtree(int t,int tl,int tr){
    if (tl==tr){
        T[t] = abs(A[tl]-A[tl-1]);
        return;
    }
    int tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = __gcd(T[t*2+1],T[t*2+2]);
};
ll get(int t,int tl,int tr,int l,int r){
    if (tl>r || l>tr)
        return 0;
    if (l<=tl && tr<=r){
        return T[t];
    }
    int tm = (tl+tr)/2;
    return __gcd(get(t*2+1,tl,tm,l,r),get(t*2+2,tm+1,tr,l,r));
}
void solve(){
    int n;
    cin>>n;
    --n;
    for(int i = 0;i<=n;++i){
        cin>>A[i];
    }
    if (n==0){
        cout<<1<<endl;
        return;
    }
    buildtree(0,1,n);
    int ptr = 1,res = 1;
    for(int i = 1;i<=n;++i){
        while(ptr<i && get(0,1,n,ptr,i)==1)
            ++ptr;
        if (get(0,1,n,ptr,i)!=1)
            res = max(res,i-ptr+2);
    }
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    //t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}