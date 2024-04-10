#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct seg_tree{
    vector<int> seg;
    function<int(int,int)> func=plus<>();
    int n;
    seg_tree(int n){this->n=n;seg.resize(n*2);}
    void set_func(function<int(int,int)> f){func=f;}
    void update(int a,int b){
        seg[a+=n]=b;
        for(a>>=1;a;a>>=1)seg[a]=func(seg[a*2],seg[a*2+1]);
    }
    int query(int a,int b){
        a+=n,b+=n;
        if(a==b)return seg[a];
        int l=seg[a++],r=seg[b--];
        for(;a<=b;a>>=1,b>>=1){
            if(a&1)l=func(l,seg[a]),a++;
            if(!(b&1))r=func(seg[b],r),b--;
        }
        return func(l,r);
    }
};
int mini(const int&a,const int&b){return a<b?a:b;}
int maxi(const int&a,const int&b){return a>b?a:b;}
int main(){
    int n,s,l,i,x;
    scanf("%d%d%d",&n,&s,&l);
    seg_tree a(n+1),b(n+1),g(n+1);
    a.set_func(mini),b.set_func(maxi),g.set_func(mini);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        a.update(i,x);
        b.update(i,x);
        int cur=i;
        for(int j=1<<16;j;j>>=1){
            if(cur-j<0)continue;
            if(b.query(cur-j+1,i)-a.query(cur-j+1,i)<=s)cur-=j;
        }
        int ans;
        if(i-cur<l)ans=0x3f3f3f3f;
        else ans=g.query(cur,i-l)+1;
        if(i==n)printf("%d",ans>n?-1:ans);
        g.update(i,ans);
    }
}