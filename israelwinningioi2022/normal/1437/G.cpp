#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;

struct SEG{
    int sz;
    vi a;
    void init(int n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz,-1);
    }
    int query(int l, int r){
        //cout<<"LR: "<<l<<" "<<r<<endl;
        int res = -1;
        for(l+=sz, r+=sz; l<=r;l/=2,r/=2){
            if (l%2==1) chkmax(res, a[l++]);
            if (r%2==0) chkmax(res, a[r--]);
        }
        return res;
    }
    void update(int i, int x){
        a[i+=sz]=x;
        //cout<<"HI: "<<i<<" "<<x<<endl;
        for(i/=2;i;i/=2) a[i] = max(a[2*i], a[2*i+1]);
    }
};
template<int V>
class HLD{
    int n,s;
    int parent[V], heavy[V], depth[V];
    int treePos[V], root[V];
    SEG seg;
    int dfs(const vvi& g, int cur, int p=-1, int d=0){
        depth[cur] = d; parent[cur] = p;
        int maxsz=0, sz=1; heavy[cur] = -1;
        for(auto nei:g[cur]) if (nei!=p){
            int sub = dfs(g, nei, cur, d+1);
            sz+=sub;
            if (sub>maxsz){
                heavy[cur] = nei;
                maxsz = sub;
            }
        }
        return sz;
    }
    template<class BinaryOperation>
    void doPath(int u, int v,BinaryOperation op){
        for(;root[u]!=root[v]; u = parent[root[u]]){
            if (depth[root[u]]<depth[root[v]]) swap(u,v);
            op(treePos[root[u]], treePos[u]);
        }
        if (depth[u]<depth[v]) swap(u,v);
        op(treePos[v], treePos[u]);
    }
public:
    void init(const vvi& g, int _s=0){
        s = _s;
        n = g.size();
        dfs(g,s);
        int curp = 0;
        loop(i,0,n){
            if (parent[i]==-1 || heavy[parent[i]]!=i){
                for(int j=i;j!=-1;j=heavy[j]) treePos[j]=curp++, root[j]=i;
            }
        }
        seg.init(n);
    }
    void set(int u, int x){
        seg.update(treePos[u],x);
    }
    int query(int u){
        int res = -1;
        doPath(s,u,[this, &res](int l, int r){
            chkmax(res, seg.query(l,r));
        });
        return res;
    }
};

struct AhoCorasick{
    vector<map<char,int>> to;
    vi link;
    vvi g;
    int sz=1;
    AhoCorasick(): to(vector<map<char,int>>(1)){}
    int push_word(string& s){
        int cur = 0;
        for(auto& c: s){
            if (!to[cur][c]) {
                to[cur][c] = sz++;
                to.pb(map<char,int>());
            }
            cur = to[cur][c];
        }
        return cur;
    }
    void create_links(){
        queue<int> q;
        q.push(0);
        link.resize(to.size(),0);
        g.resize(to.size());
        link[0] = -1;
        int v,u,j;
        char c;
        while(q.size()){
            v = q.front();
            q.pop();
            for(auto& it:to[v]){
                c = it.x;
                u = it.y;
                j = link[v];
                while(j!=-1 && !to[j][c]) j = link[j];
                if (j!=-1) link[u] = to[j][c];
                else link[u] = 0;
                g[link[u]].pb(u);
                q.push(u);
            }
        }
    }
    int next_state(int cur, char c){
        while(cur!=-1 && !to[cur][c]) cur = link[cur];
        if (cur==-1) return 0;
        return to[cur][c];
    }
};
const int MAXN = 3e5+10;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    AhoCorasick aho;
    vi p(n);
    string s; 
    loop(i,0,n){
        cin>>s;
        p[i] = aho.push_word(s);
    }
    aho.create_links();
    //int r = aho.g.size(); cout<<"G: "<<r<<endl;
    //loop(i,0,r){cout<<"NEIS: "<<i<<": "; for(int nei:aho.g[i]) cout<<nei<<" "; cout<<endl;}
    HLD<MAXN> hld; hld.init(aho.g,0);
    vector<set<ii>> vals(aho.g.size());
    vi val(n,0);
    loop(i,0,n) {
        vals[p[i]].insert({0,i});
        hld.set(p[i], 0);
    }
    int op;
    loop(i,0,q){
        cin>>op;
        if (op==1){
            int ind,x; cin>>ind>>x; ind--;
            vals[p[ind]].erase({val[ind], ind});
            val[ind] = x;
            vals[p[ind]].insert({val[ind], ind});
            //cout<<"SET: "<<p[ind]<<endl;
            hld.set(p[ind],vals[p[ind]].rbegin()->x);
        }
        else{
            int cur = 0, ans = -1;
            cin>>s;
            for(char c:s){
                cur = aho.next_state(cur, c);
                int v = hld.query(cur);
                //cout<<"CUR: "<<cur<<" "<<v<<endl;
                chkmax(ans, v);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
/*
color a
cls
g++ g.cpp -o b & b
6 15
a
ab
ba
b
a
ba
2 aa
1 4 4
2 bbb
1 2 1
1 2 18
2 b
2 c
1 6 10
2 aba
2 abbbba
1 2 12
2 bbaaab
1 1 11
1 5 5
2 baa




5 8
kurou
takuo
takeshi
naomi
shingo
2 nakiraomi
2 abanaomicaba
1 3 943
2 takuotakeshishingo
1 5 135832
2 shingotakeshi
1 5 0
2 shingotakeshi



*/