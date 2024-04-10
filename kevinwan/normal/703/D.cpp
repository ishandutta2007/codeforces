#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
struct seg_tree{
    vector<T> seg;
    function<T(T,T)> func=plus<>();
    int n;
    seg_tree(int n){this->n=n;seg.resize(n*2);}
    void set_func(function<T(T,T)> f){func=f;}
    void update(int a,T b){
        seg[a+=n]=b;
        for(a>>=1;a;a>>=1)seg[a]=func(seg[a*2],seg[a*2+1]);
    }
    int query(int a,int b){
        a+=n,b+=n;
        if(a==b)return seg[a];
        T l=seg[a++],r=seg[b--];
        for(;a<=b;a>>=1,b>>=1){
            if(a&1)l=func(l,seg[a]),a++;
            if(!(b&1))r=func(seg[b],r),b--;
        }
        return func(l,r);
    }
};
const int mn=1e6+10;
int num[mn],psa[mn],bit[mn],ans[mn];
struct qu{
    int l,r,i;
};
bool comp(const qu&a,const qu&b){return a.l>b.l;}
qu q[mn];
unordered_map<int,int> ln;
void up(int a,int b){for(;a<mn;a+=a&-a)bit[a]^=b;}
int que(int a){int b=0;for(;a;a-=a&-a)b^=bit[a];return b;}
int main(){
    int n,m,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",num+i),psa[i]=psa[i-1]^num[i];
    scanf("%d",&m);
    for(i=0;i<m;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].i=i;
    sort(q,q+m,comp);
    int cur=n+1;
    for(i=0;i<m;i++){
        while(q[i].l<cur){
            cur--;
            up(cur,num[cur]);
            int k=ln[num[cur]];
            if(k)up(k,num[cur]);
            ln[num[cur]]=cur;
        }
        ans[q[i].i]=que(q[i].r)^psa[q[i].r]^psa[q[i].l-1];
    }
    for(i=0;i<m;i++)printf("%d\n",ans[i]);
}