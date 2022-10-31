#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define endl '\n'
const int N = 4E5+7;
struct node{
    int first,second,pos,fin;
} A[N];
bool mc(node a,node b){
    if (a.second==b.second)
        return a.first>b.first;
    return a.second<b.second;
}
bool mc1(node a,node b){
    return a.first>b.first;
}
bool mc2(node a,node b){
    return a.fin>b.fin;
}
ll fact[N],rev[N];
const ll MOD = 998244353;
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        mult = mult*mult%MOD;
        power = power>>1;
    }
    return x;
}
ll C(int n,int k){
    if (n<0 || k<0 || n<k)
        return 0;
    return ((fact[n]*rev[k])%MOD*rev[n-k])%MOD;
}
struct tnode{
    int l = -1,r = -1,val = 0,sz = 1,cursz = 1;
} T[N];
int ptr;
int merge(int l,int r){
    if (l==-1 || r==-1)
        return l==-1?r:l;
    if (rand()&1){
        T[l].sz+=T[r].sz;
        T[l].r = merge(T[l].r,r);
        return l;
    }
    else {
        T[r].sz+=T[l].sz;
        T[r].l = merge(l,T[r].l);
        return r;
    }
}
int sz(int v){
    if (v==-1)
        return 0;
    return T[v].sz;
}
pair<int,int> split(int t,int pos,int cur){
    if (cur>=pos)
        return {-1,t};
    if (pos>cur+sz(t))
        return {t,-1};
    if (t==-1)
        return {-1,-1};
    if (sz(T[t].l)+cur<pos && T[t].cursz+sz(T[t].l)+cur>pos){
        int need = pos-cur-sz(T[t].l);
        int new_node = ++ptr;
        T[new_node] = {-1,-1,0,T[t].cursz-need,T[t].cursz-need};
        T[t].cursz = need;
        T[t].r = merge(new_node,T[t].r);
    }
    if (sz(T[t].l)+cur+T[t].cursz<=pos){
        T[t].sz-=T[T[t].r].sz;
        pair<int,int> spl = split(T[t].r,pos,T[T[t].l].sz+cur+T[t].cursz);
        T[t].r = spl.first;
        T[t].sz += T[T[t].r].sz;
        return {t,spl.second};
    }
    else{
        T[t].sz-=T[T[t].l].sz;
        pair<int,int> spl = split(T[t].l,pos,cur);
        T[t].l = spl.second;
        T[t].sz+=T[T[t].l].sz;
        return {spl.first,t};
    }
}
int insert(int root,int pos,int val){
    if (root==-1){
        root = 0;
        ptr = 0;
        T[root].val = val;
        T[root].sz = T[root].cursz = 1;
        T[root].l=T[root].r = -1;
        return root;
    }
    else{
        pair<int,int> spl = split(root,pos-1,0);
        T[++ptr] = tnode{-1,-1,val,1,1};
        spl.first = merge(spl.first,ptr);
        return merge(spl.first,spl.second);
    }
}
map<int,int> in_pos;
void order(int t){
    if (t==-1)
        return;
    order(T[t].l);
    if (T[t].val!=0)
    in_pos[T[t].val] = ++ptr;
    order(T[t].r);
}
void solve(){
    int n,m;
    cin>>n>>m;
    ptr = 0;
    int root = -1;
    for(int i = 1;i<=m;++i){

        cin>>A[i].first>>A[i].second;
        if (A[i].first-A[i-1].first-1){
            int new_node = ++ptr;
            T[new_node] = {-1,-1,0,A[i].first-A[i-1].first-1,A[i].first-A[i-1].first-1};
            root = merge(root,new_node);
        }

        root = insert(root,A[i].second,A[i].first);
    }
    ptr = 0;
    order(root);
    //ptr = 0;
    for(int i = 1;i<=m;++i){
        A[i].pos = in_pos[A[i].first];
    }
    sort(A+1,A+1+m,mc1);
    super_set S;
    for(int i = 1;i<=m;++i){
        A[i].fin = A[i].first-A[i].second+(n-A[i].first)-S.order_of_key(A[i].pos);
        S.insert(A[i].pos);
    }
    sort(A+1,A+1+m,mc2);
    int cnt = 0;
    for(int i = 1;i<=m;++i){
        if (!(i+1<=m && A[i].fin-1==A[i+1].fin && A[i+1].first>A[i].first))
            ++cnt;
    }

    cout<<C(2*n-cnt-1,n)<<endl;
    in_pos.clear();
}
int main() {
    fact[0] = rev[0] = 1;
    for(int i = 1;i<N;++i){
        fact[i] = fact[i-1]*i%MOD;
        rev[i] = binpow(fact[i],MOD-2);
    }
    int t;
    t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}