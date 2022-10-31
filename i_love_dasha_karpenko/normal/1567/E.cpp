//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gt(tuple,el) (get<el>(tuple))
const int N = 2e5+7;
struct tnode{
    ll len,len_l,len_r,el_l,el_r,cnt;
} T[N*4];
int A[N];
tnode merge(tnode l,tnode r){
    if (l.len==0)
        return r;
    if (r.len==0)
        return l;
    tnode ret;
    ret.cnt = r.cnt+l.cnt;
    ret.el_l = l.el_l;
    ret.el_r = r.el_r;
    ret.len_r = r.len_r;
    ret.len_l = l.len_l;
    ret.len = l.len+r.len;
    if (l.el_r<=r.el_l){
        ret.cnt+=l.len_r*r.len_l;
        if (ret.len_l==l.len)
            ret.len_l+=r.len_l;
        if (ret.len_r==r.len)
            ret.len_r+=l.len_r;
    }
    return ret;
}
void buildtree(int t,int tl,int tr){
    if (tl==tr){
        T[t] = {1,1,1,A[tl],A[tl],1};
        return;
    }
    int tm = (tl+tr)>>1;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = merge(T[t*2+1],T[t*2+2]);
}
void update(int t,int tl,int tr,int pos,int val){
    if (tl>pos || tr<pos)
        return;
    if (tl==tr){
        A[tl] = val;
        T[t] = {1,1,1,A[tl],A[tl],1};
        return;
    }
    int tm = (tl+tr)>>1;
    update(t*2+1,tl,tm,pos,val);
    update(t*2+2,tm+1,tr,pos,val);
    T[t] = merge(T[t*2+1],T[t*2+2]);
}
tnode get(int t,int tl,int tr,int l,int r){
    if (tl>r || l>tr)
        return {0,0,0,0,0,0};
    if (l<=tl && tr<=r)
        return T[t];
    int tm = (tl+tr)>>1;
    return merge(get(t*2+1,tl,tm,l,r),get(t*2+2,tm+1,tr,l,r));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    buildtree(0,1,n);
    while(q--){
        int type;
        cin>>type;
        if (type==1){
            int pos,val;
            cin>>pos>>val;
            update(0,1,n,pos,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<get(0,1,n,l,r).cnt<<endl;
        }
    }
    return 0;
}