#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')

struct tnode{
    int l,r,mi,mx,upd;
    tnode(int _l = -1,int _r = -1,int _mi = 0,int _mx = 0,int _upd = 0){
        l = _l; r = _r; mi = _mi; mx = _mx; upd = _upd;
    }
    void add(int val){
        upd+=val,mi+=val,mx+=val;
    }
};
const int N = 2e5+7;
const int LOG = 21;
struct tree{
    tnode T[N*LOG*4];
    int root;
    int lb,rb;
    int ptr;
    int new_node(tnode val = tnode()){
        T[ptr] = tnode(val);
        return ptr++;
    }
    tree(int _lb = 0,int _rb = 0){
        lb = _lb, rb = _rb;
        ptr = 0;
        root = new_node(tnode(-1,-1,lb,rb,0));
    }
    void push(int t){
        T[T[t].l].add(T[t].upd);
        T[T[t].r].add(T[t].upd);
        T[t].upd = 0;
    }
    tnode merge(tnode a,tnode b,tnode ref){
        ref.mx = max(a.mx,b.mx);
        ref.mi = min(a.mi,b.mi);
        return ref;
    }
    void cnode(int t,int tl,int tm,int tr){
        if (T[t].l==-1)
            T[t].l = new_node(tnode(-1,-1,tl,tm,0));
        if (T[t].r==-1)
            T[t].r = new_node(tnode(-1,-1,tm+1,tr,0));
    }
    void upd(int t,int tl,int tr,int l,int r,int val){
        if (tl>r || l>tr)
            return;
        if (l<=tl && tr<=r){
            T[t].add(val);
            return;
        }
        int tm = (tl+tr)>>1;
        cnode(t,tl,tm,tr);
        push(t);

        upd(T[t].l,tl,tm,l,r,val);
        upd(T[t].r,tm+1,tr,l,r,val);
        T[t] = merge(T[T[t].l],T[T[t].r],T[t]);
    }
    int get_left(int t,int tl,int tr,int val){
        if (T[t].mx<val)
            return tr;
        if (T[t].mi>=val)
            return tl-1;
        if (tl==tr)
            return tl;
        int tm = (tl+tr)>>1;
        cnode(t,tl,tm,tr);
        push(t);
        int ret = get_left(T[t].l,tl,tm,val);
        if (ret==tm)
            return max(ret,get_left(T[t].r,tm+1,tr,val));
        return ret;
    }
    int get_right(int t,int tl,int tr,int val){
        if (T[t].mi>val)
            return tl;
        if (T[t].mx<=val)
            return tr+1;
        if (tl==tr)
            return tl;
        int tm = (tl+tr)>>1;
        cnode(t,tl,tm,tr);
        push(t);
        int ret = get_right(T[t].r,tm+1,tr,val);
        if (ret==tm+1)
            return min(ret,get_right(T[t].l,tl,tm,val));
        return ret;
    }
    int get(int t,int tl,int tr,int pos){
        if (tl>pos || tr<pos)
            return 0;
        if (tl==tr)
            return T[t].mi;
        int tm = (tl+tr)>>1;
        cnode(t,tl,tm,tr);
        push(t);
        return max(get(T[t].l,tl,tm,pos),get(T[t].r,tm+1,tr,pos));
    }
    // user func
    void update(int l,int r,int val){
        upd(root,lb,rb,l,r,val);
    }
    int gl(int val){
        return get_left(root,lb,rb,val);
    }
    int gr(int val){
        return get_right(root,lb,rb,val);
    }
    int get_val(int val){
        return get(root,lb,rb,val);
    }
};
tree T(0,1e9);
void solve() {
    int n;
    cin>>n;
    int lastans = 0;
    const int MOD = 1e9+1;
    for(int i = 1;i<=n;++i){
        int cur;
        cin>>cur;
        int l = T.gl(cur);
        int r = T.gr(cur);
        if (l>=T.lb)
            T.update(T.lb,l,1);
        if (r<=T.rb)
            T.update(r,T.rb,-1);
        int k;
        cin>>k;
        while(k--){
            int val;
            cin>>val;
            val = (val+lastans)%MOD;

            lastans = T.get_val(val);
            cout<<lastans<<endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}