#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
struct seg_tree{
    vector<T> seg;
    function<T(T,T)> func=plus<>();
    int n;
    seg_tree(int n){set_size(n);}
    seg_tree(){}
    void set_size(int n){this->n=n;seg.resize(n*2);}
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
int n,m,k;
int maxi(int a,int b){return a>b?a:b;}
int t[100005][5];
int pos[5],posv;
seg_tree<int> s[5];
bool test(int x){
    int i,j;
    for(i=0;i+x<=n;i++){
        posv=0;
        for(j=0;j<5;j++)pos[j]=s[j].query(i,i+x-1),posv+=pos[j];
        if(posv<=k)return 1;
    }
    return 0;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    int i,j;
    for(i=0;i<5;i++)s[i].set_size(n+5),s[i].set_func(maxi);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)scanf("%d",&t[i][j]),s[j].update(i,t[i][j]);
    }
    int cur=0;
    for(i=1<<16;i;i>>=1){
        if(test(cur+i))cur+=i;
    }
    test(cur);
    printf("%d",pos[0]+k-posv);
    for(i=1;i<m;i++)printf(" %d",pos[i]);
}