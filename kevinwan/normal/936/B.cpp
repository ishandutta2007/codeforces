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
vector<int> g[200001];
bool vis[200001][2];
bool ins[200001];
bool pr;
bool cyc;
int s;
vector<int> v;
void dfs(int x,bool o){
    if(o&&g[x].size()==0){
        pr=1;
        v.push_back(x);
        return;
    }
    vis[x][o]=1;
    ins[x]=1;
    for(int y:g[x]){
        if(ins[y]){
            cyc=1;
        }
        if(vis[y][o^1])continue;
        dfs(y,o^1);
        if(pr){
            v.push_back(x);
            return;
        }
    }
    ins[x]=0;
}
int main(){
    int n,m,i,j,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        for(j=1;j<=a;j++)scanf("%d",&b),g[i].push_back(b);
    }
    scanf("%d",&s);
    dfs(s,0);
    if(pr){
        printf("Win\n");
        for(i=v.size()-1;i>=0;i--)printf("%d ",v[i]);
    }
    else if(cyc)printf("Draw");
    else printf("Lose");
}