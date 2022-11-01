#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 18;
const ll mod=998244353;
int a[(1<<N)];
int L[(1<<N)*2],R[(1<<N)*2];
vector<int>sw[N];
struct node{
    ll sum;
    ll pref;
    ll suf;
    ll ans;
    node(){
        sum=0;
        pref=0;
        suf=0;
        ans=0;
    }
};
node Merge(node A,node B){
    node C;
    C.sum=A.sum+B.sum;
    C.pref=max(A.pref,A.sum+B.pref);
    C.suf=max(B.suf,A.suf+B.sum);
    C.ans=max({A.ans,B.ans,A.suf+B.pref});
    return C;
}
node t[(1<<N)*2];
void build(int v,int l,int r,int depth){
    if (depth==-1){
        t[v].sum=a[l];
        t[v].ans=t[v].pref=t[v].suf=max(a[l],0);
        return;
    }
    sw[depth].push_back(v);
    L[v]=v+v;
    R[v]=v+v+1;
    int m=(l+r)/2;
    build(L[v],l,m,depth-1);
    build(R[v],m+1,r,depth-1);
    t[v]=Merge(t[L[v]],t[R[v]]);
}
void Go(int v){
    swap(L[v],R[v]);
    while (v){
        t[v]=Merge(t[L[v]],t[R[v]]);
        v/=2;
    }
}
ll ans[(1<<N)*2];
void solve(){
    int n;cin>>n;
    for (int i=0;i<(1<<n);i++) cin>>a[i];
    build(1,0,(1<<n)-1,n-1);
    vector<int>xr;
    for (int i=n-1;i>=0;i--){
        vector<int>nw=xr;
        nw.push_back(i);
        for (int x:xr) nw.push_back(x);
        xr=nw;
    }
    ans[0]=t[1].ans;
    int mask=0;
    for (int bt:xr){
        mask^=(1<<bt);
        for (int v:sw[bt]){
            Go(v);
        }
        ans[mask]=t[1].ans;
    }
    int q;cin>>q;
    mask=0;
    for (int i=1;i<=q;i++){
        int k;cin>>k;
        mask^=(1<<k);
        cout<<ans[mask]<<'\n';
    }



}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}