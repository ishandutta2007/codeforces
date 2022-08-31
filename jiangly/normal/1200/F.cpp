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
ll readLong(){
    ll x=0;
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
void solve_single_test(int test_id=1){
    const int P=2520;
    int n=readInt();
    vector<int> k(n);
    for(int i=0;i<n;++i){
        k[i]=(readInt()%P+P)%P;
    }
    vector<int> m(n);
    vector<vector<int>> edge(n);
    for(int i=0;i<n;++i){
        m[i]=readInt();
        edge[i].resize(m[i]);
        for(int j=0;j<m[i];++j){
            edge[i][j]=readInt()-1;
        }
    }
    vector<vector<int>> count(n,vector<int>(P,-1));
    vector<vector<int>> instack(n,vector<int>(P,-1));
    vector<bool> vis(n);
    for(int u=0;u<n;++u){
        for(int c=0;c<P;++c){
            if(count[u][c]!=-1){
                continue;
            }
            vector<pair<int,int>> stk;
            int v=u;
            int x=c;
            int ans;
            while(instack[v][x]==-1){
                instack[v][x]=stk.size();
                stk.emplace_back(v,x);
                x=(x+k[v])%P;
                v=edge[v][x%m[v]];
            }
            if(count[v][x]!=-1){
                ans=count[v][x];
            }else{
                ans=0;
                for(int i=instack[v][x];i<stk.size();++i){
                    int w=stk[i].first;
                    if(!vis[w]){
                        ++ans;
                    }
                    vis[w]=true;
                }
                for(int i=instack[v][x];i<stk.size();++i){
                    int w=stk[i].first;
                    vis[w]=false;
                }
            }
            for(auto [v,x]:stk){
                count[v][x]=ans;
            }
        }
    }
    int q=readInt();
    while(q--){
        int u=readInt()-1;
        int c=(readInt()%P+P)%P;
        printf("%d\n",count[u][c]);
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