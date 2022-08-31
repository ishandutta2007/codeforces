#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int INF=1e9;
const LL LLINF=1e18;
template<class T>void chkmin(T &x,const T &y){
    if(y<x){
        x=y;
    }
}
template<class T>void chkmax(T &x,const T &y){
    if(y>x){
        x=y;
    }
}
template<class T>void sort(vector<T> &a){
    sort(a.begin(),a.end());
}
template<class T>void reverse(vector<T> &a){
    reverse(a.begin(),a.end());
}
void reverse(string &a){
    reverse(a.begin(),a.end());
}
template<class T,class Cmp>void sort(vector<T> &a,Cmp cmp){
    sort(a.begin(),a.end(),cmp);
}
template<class T>void unique(vector<T> &a){
    a.resize(unique(a.begin(),a.end())-a.begin());
}
class IO{
private:
static const int BUF_SIZE=1<<22;
char in_buf[BUF_SIZE];
char out_buf[BUF_SIZE];
char *in_p1,*in_p2,*out_p;
char stk[20];
public:
IO():in_p1(in_buf),in_p2(in_buf),out_p(out_buf){}
~IO(){
    fwrite(out_buf,1,out_p-out_buf,stdout);
}
char get(){
    return in_p1==in_p2&&(in_p2=(in_p1=in_buf)+fread(in_buf,1,BUF_SIZE,stdin),in_p1==in_p2)?EOF:*in_p1++;
}
void put(char c){
    *out_p++=c;
    out_p==out_buf+BUF_SIZE?fwrite(out_buf,1,BUF_SIZE,stdout):0;
}
IO& operator >>(int &x){
    x=0;
    char c=get();
    bool sign=false;
    while(!isdigit(c)){
        sign=(c=='-');
        c=get();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-'0';
        c=get();
    }
    if(sign){
        x=-x;
    }
    return *this;
}
IO& operator >>(LL &x){
    x=0;
    char c=get();
    bool sign=false;
    while(!isdigit(c)){
        sign=(c=='-');
        c=get();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-'0';
        c=get();
    }
    if(sign){
        x=-x;
    }
    return *this;
}
IO& operator <<(int x){
    if(x<0){
        put('-');
        x=-x;
    }
    if(x==0){
        put('0');
    }
    int top=0;
    while(x>0){
        stk[top++]=x%10+'0';
        x/=10;
    }
    while(top>0){
        put(stk[--top]);
    }
    return *this;
}
IO& operator <<(LL x){
    if(x<0){
        put('-');
        x=-x;
    }
    if(x==0){
        put('0');
    }
    int top=0;
    while(x>0){
        stk[top++]=x%10+'0';
        x/=10;
    }
    while(top>0){
        put(stk[--top]);
    }
    return *this;
}
IO& operator <<(char c){
    put(c);
    return *this;
}
IO& operator <<(const string &s){
    for(char c:s){
        put(c);
    }
    return *this;
}
void flush(){
    fwrite(out_buf,1,out_p-out_buf,stdout);
    out_p=out_buf;
    fflush(stdout);
}
}io;
void solve_single_test(int test_id=1){
    int n;
    io>>n;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;++i){
        int u,v;
        io>>u>>v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> sz(n),mx(n);
    function<void(int,int)> dfs=[&](int u,int f){
        sz[u]=1;
        mx[u]=0;
        for(int v:g[u]){
            if(v==f){
                continue;
            }
            dfs(v,u);
            sz[u]+=sz[v];
            chkmax(mx[u],sz[v]);
        }
        chkmax(mx[u],n-sz[u]);
    };
    dfs(0,-1);
    int r=0;
    for(int i=1;i<n;++i){
        if(mx[i]<mx[r]){
            r=i;
        }
    }
    dfs(r,-1);
    sort(g[r].begin(),g[r].end(),[&](int x,int y){
        return sz[x]>sz[y];
    });
    vector<int> a,b;
    int suma=0,sumb=0;
    for(int v:g[r]){
        if(suma<sumb){
            a.push_back(v);
            suma+=sz[v];
        }else{
            b.push_back(v);
            sumb+=sz[v];
        }
    }
    vector<int> w(n);
    w[r]=0;
    function<void(int,int,int)> dfsSol=[&](int u,int f,int step){
        io<<u+1<<' '<<f+1<<' '<<w[u]-w[f]<<'\n';
        int x=w[u];
        for(int v:g[u]){
            if(v==f){
                continue;
            }
            w[v]=x+step;
            x+=step*sz[v];
            dfsSol(v,u,step);
        }
    };
    int x=0;
    for(int v:a){
        w[v]=x+sumb+1;
        x+=(sumb+1)*sz[v];
        dfsSol(v,r,sumb+1);
    }
    x=0;
    for(int v:b){
        w[v]=x+1;
        x+=sz[v];
        dfsSol(v,r,1);
    }
}
void solve_multiple_tests(){
    int n_tests;
    io>>n_tests;
    for(int i=1;i<=n_tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}