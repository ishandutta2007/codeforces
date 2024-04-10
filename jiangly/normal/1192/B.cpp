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
class SegTree{
private:
struct Node{
ll mx,lazy;
Node():mx(0),lazy(0){}
};
int sz;
vector<Node> t;
void pushup(int p){
    t[p].mx=max(t[p*2].mx,t[p*2+1].mx);
}
void pushdown(int p){
    t[p*2].lazy+=t[p].lazy;
    t[p*2].mx+=t[p].lazy;
    t[p*2+1].lazy+=t[p].lazy;
    t[p*2+1].mx+=t[p].lazy;
    t[p].lazy=0;
}
void rangeadd(int p,int l,int r,int L,int R,ll x){
    if(l>=R||r<=L){
        return;
    }
    if(l>=L&&r<=R){
        t[p].lazy+=x;
        t[p].mx+=x;
        return;
    }
    pushdown(p);
    rangeadd(p*2,l,(l+r)/2,L,R,x);
    rangeadd(p*2+1,(l+r)/2,r,L,R,x);
    pushup(p);
}
ll rangemax(int p,int l,int r,int L,int R){
    if(l>=R||r<=L){
        return 0;
    }
    if(l>=L&&r<=R){
        return t[p].mx;
    }
    pushdown(p);
    ll lc=rangemax(p*2,l,(l+r)/2,L,R);
    ll rc=rangemax(p*2+1,(l+r)/2,r,L,R);
    return max(lc,rc);
}
public:
SegTree(int n=1){
    sz=1;
    while(sz<n){
        sz*=2;
    }
    t.resize(sz*2);
}
void rangeadd(int L,int R,ll x){
    rangeadd(1,0,sz,L,R,x);
}
ll rangemax(int L,int R){
    return rangemax(1,0,sz,L,R);
}
};
class heap{
private:
priority_queue<ll> h1,h2;
void check(){
    while(!h2.empty()&&h1.top()==h2.top()){
        h1.pop();
        h2.pop();
    }
}
public:
void insert(ll x){
    h1.push(x);
}
void erase(ll x){
    h2.push(x);
}
ll top(){
    check();
    return h1.empty()?0:h1.top();
}
ll get2(){
    ll x=top();
    h1.pop();
    ll y=top();
    h1.push(x);
    return x+y;
}
};
void solve_single_test(int test_id=1){
    int n=readInt();
    int q=readInt();
    vector<vector<int>> edge(n);
    vector<bool> used(n);
    vector<vector<int>> parent(n),in(n),out(n),belong(n);
    vector<int> sub(n);
    vector<SegTree> T(n);
    heap ans;
    vector<heap> chain(n);
    ll w_limit=readLong();
    vector<tuple<int,int,ll>> edges(n-1);
    for(int i=0;i<n-1;++i){
        int a=readInt()-1;
        int b=readInt()-1;
        ll w=readLong();
        edge[a].push_back(b);
        edge[b].push_back(a);
        edges[i]={a,b,w};
    }
    function<void(int,int)> dfsSize=[&](int u,int p){
        sub[u]=1;
        for(int v:edge[u]){
            if(v==p||used[v]){
                continue;
            }
            dfsSize(v,u);
            sub[u]+=sub[v];
        }
    };
    function<int(int,int,int)> findCentroid=[&](int u,int p,int sz){
        for(int v:edge[u]){
            if(v==p||used[v]){
                continue;
            }
            if(sub[v]*2>=sz){
                return findCentroid(v,u,sz);
            }
        }
        return u;
    };
    int dfstm;
    function<void(int,int)> dfsSeg=[&](int u,int s){
        in[u].push_back(dfstm++);
        belong[u].push_back(s);
        for(int v:edge[u]){
            if(v==parent[u].back()||used[v]){
                continue;
            }
            parent[v].push_back(u);
            if(s==-1){
                dfsSeg(v,v);
                chain[u].insert(0);
            }else{
                dfsSeg(v,s);
            }
        }
        out[u].push_back(dfstm);
    };
    function<void(int)> work=[&](int u){
        dfsSize(u,-1);
        u=findCentroid(u,-1,sub[u]);
        dfstm=0;
        parent[u].push_back(-1);
        dfsSeg(u,-1);
        ans.insert(0);
        T[u]=SegTree(out[u].back());
        used[u]=true;
        for(int v:edge[u]){
            if(used[v]){
                continue;
            }
            work(v);
        }
    };
    work(0);
    auto updateWeight=[&](int u,int v,ll x){
        for(int i=0;i<parent[u].size()&&i<parent[v].size();++i){
            int a=parent[u][i]==v?u:v;
            int b=belong[a][i];
            int c=parent[b][i];
            ans.erase(chain[c].get2());
            chain[c].erase(T[c].rangemax(in[b][i],out[b][i]));
            T[c].rangeadd(in[a][i],out[a][i],x);
            chain[c].insert(T[c].rangemax(in[b][i],out[b][i]));
            ans.insert(chain[c].get2());
        }
    };
    for(int i=0;i<n-1;++i){
        updateWeight(get<0>(edges[i]),get<1>(edges[i]),get<2>(edges[i]));
    }
    ll last=0;
    for(int i=0;i<q;++i){
        int d=(readInt()+last)%(n-1);
        ll x=(readLong()+last)%w_limit;
        updateWeight(get<0>(edges[d]),get<1>(edges[d]),x-get<2>(edges[d]));
        get<2>(edges[d])=x;
        printf("%I64d\n",last=ans.top());
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