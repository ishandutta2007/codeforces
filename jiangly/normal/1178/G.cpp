#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
template<class T,class Cmp>void sort(vector<T> &a,Cmp cmp){
    sort(a.begin(),a.end(),cmp);
}
template<class T>void unique(vector<T> &a){
    a.resize(unique(a.begin(),a.end())-a.begin());
}
int readInt(){
    int x=0;
    bool sign=false;
    char c=getchar();
    while(!isdigit(c)){
        sign=c=='-';
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return sign?-x:x;
}
string readString(){
    string s;
    char c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(!isspace(c)){
        s+=c;
        c=getchar();
    }
    return s;
}
class vec{
public:
ll x,y;
vec(ll x=0,ll y=0):x(x),y(y){}
};
vec operator+(const vec &a,const vec &b){
    return {a.x+b.x,a.y+b.y};
}
vec operator-(const vec &a,const vec &b){
    return {a.x-b.x,a.y-b.y};
}
double cross_product(const vec &a,const vec &b){
    return 1.0*a.x*b.y-1.0*a.y*b.x;
}
void solve_single_test(int test_id=1){
    const double eps=1e-6;
    int n=readInt();
    int q=readInt();
    int block_size=sqrt(max(1,n/6));
    int n_blocks=(n+block_size-1)/block_size;
    vector<vector<int>> son(n);
    for(int i=1;i<n;++i){
        int fa=readInt()-1;
        son[fa].push_back(i);
    }
    vector<int> a(n),b(n),c(n),d(n);
    for(int i=0;i<n;++i){
        c[i]=readInt();
    }
    for(int i=0;i<n;++i){
        d[i]=readInt();
    }
    int tim=0;
    vector<int> st(n),ed(n);
    function<void(int)> dfs=[&](int u){
        st[u]=tim++;
        for(int v:son[u]){
            c[v]+=c[u];
            d[v]+=d[u];
            dfs(v);
        }
        ed[u]=tim-1;
    };
    dfs(0);
    for(int i=0;i<n;++i){
        a[st[i]]=c[i];
        b[st[i]]=d[i];
    }
    vector<vector<int>> points(n_blocks);
    vector<vector<vec>> U(n_blocks),D(n_blocks);
    vector<int> X(n_blocks),UP(n_blocks),DP(n_blocks);
    for(int i=0;i<n;++i){
        points[i/block_size].push_back(i);
    }
    for(int i=0;i<n_blocks;++i){
        sort(points[i],[&](int x,int y){return b[x]<b[y];});
    }
    auto build_convex_hull=[&](int k){
        U[k].clear();
        D[k].clear();
        for(int i:points[k]){
            vec A(b[i],1ll*a[i]*b[i]);
            while(U[k].size()>1&&cross_product(U[k].back()-U[k][U[k].size()-2],A-U[k][U[k].size()-2])>-eps){
                U[k].pop_back();
            }
            U[k].push_back(A);
            while(D[k].size()>1&&cross_product(D[k].back()-D[k][D[k].size()-2],A-D[k][D[k].size()-2])<eps){
                D[k].pop_back();
            }
            D[k].push_back(A);
        }
        UP[k]=0;
        DP[k]=D[k].size()-1;
    };
    auto query_max=[&](int k){
        while(UP[k]+1<U[k].size()&&U[k][UP[k]].x*X[k]+U[k][UP[k]].y<=U[k][UP[k]+1].x*X[k]+U[k][UP[k]+1].y){
            ++UP[k];
        }
        while(DP[k]>0&&D[k][DP[k]].x*X[k]+D[k][DP[k]].y>=D[k][DP[k]-1].x*X[k]+D[k][DP[k]-1].y){
            --DP[k];
        }
        return (ll)max(U[k][UP[k]].x*X[k]+U[k][UP[k]].y,-D[k][DP[k]].x*X[k]-D[k][DP[k]].y);
    };
    for(int i=0;i<n_blocks;++i){
        build_convex_hull(i);
    }
    while(q--){
        int opt=readInt();
        int v,x,l,r,block_l,block_r;
        ll ans=0;
        switch(opt){
            case 1:
                v=readInt()-1;
                x=readInt();
                l=st[v];
                r=ed[v];
                block_l=l/block_size;
                block_r=r/block_size;
                if(block_l==block_r){
                    for(int i=l;i<=r;++i){
                        a[i]+=x;
                    }
                    build_convex_hull(block_l);
                }else{
                    for(int i=l;i<(block_l+1)*block_size;++i){
                        a[i]+=x;
                    }
                    for(int i=block_r*block_size;i<=r;++i){
                        a[i]+=x;
                    }
                    for(int i=block_l+1;i<block_r;++i){
                        X[i]+=x;
                    }
                    build_convex_hull(block_l);
                    build_convex_hull(block_r);
                }
                break;
            case 2:
                v=readInt()-1;
                l=st[v];
                r=ed[v];
                block_l=l/block_size;
                block_r=r/block_size;
                if(block_l==block_r){
                    for(int i=l;i<=r;++i){
                        chkmax(ans,abs(1ll*(a[i]+X[block_l])*b[i]));
                    }
                }else{
                    for(int i=l;i<(block_l+1)*block_size;++i){
                        chkmax(ans,abs(1ll*(a[i]+X[block_l])*b[i]));
                    }
                    for(int i=block_r*block_size;i<=r;++i){
                        chkmax(ans,abs(1ll*(a[i]+X[block_r])*b[i]));
                    }
                    for(int i=block_l+1;i<block_r;++i){
                        chkmax(ans,query_max(i));
                    }
                }
                printf("%I64d\n",ans);
                break;
        }
    }
}
void solve_multiple_tests(){
    int n_tests=readInt();
    for(int i=1;i<=n_tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}