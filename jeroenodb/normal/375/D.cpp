#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN = 1e5+2;
int n,m, c[mxN],sz[mxN]={},id[mxN],color[mxN],freq[mxN]={},atleast[mxN]={},rtn;
vector<int> adj[mxN];
int cnt=0;
void dfs(int at,int from =0) {
    color[cnt] = c[at];
    id[at]=cnt++;
    sz[at]++;
    for(int to:adj[at]) {
        if(to==from) continue;
        dfs(to,at);
        sz[at]+=sz[to];
    }
}
struct query {
    int l, r, k, id;
    bool operator<(const query& o) {
        int tmp = l/rtn, tmp2=o.l/rtn;
        if(tmp==tmp2) {
            return r<o.r;
        }
        return tmp < tmp2;
    }
} qs[mxN];

void Add(int i) {
    if(i<0) return;
    int tmp = ++freq[color[i]];
    if(tmp) atleast[tmp]++;
}
void Delete(int i) {
    if(i<0) return;
    int tmp = freq[color[i]]--;
    if(tmp) atleast[tmp]--;
}
int main() {

    cin >> n >> m;
    rtn = sqrt(n);
    for(int i=1;i<=n;++i) {
        cin >> c[i];
    }
    for(int i=0;i<n-1;++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for(int i=0;i<m;++i) {
        int v,k; cin >> v >> k;
        qs[i] = {id[v],id[v]+sz[v]-1,k,i};
    }
    sort(qs,qs+m);
    int l=0,r=-1;

    for(int i=0;i<m;++i) {
        auto q = qs[i];
        if(q.l>l) 
            for(int i=l;i<q.l;++i) 
                Delete(i);
        else 
            for(int i=q.l;i<l;++i)
                Add(i);
        if(q.r>r) 
            for(int i=r+1;i<=q.r;++i) 
                Add(i);
        else 
            for(int i=q.r+1;i<=r;++i) 
                Delete(i);
        c[q.id]=atleast[q.k];
        l=q.l;r=q.r;
    }
    for(int i=0;i<m;++i) {
        cout << c[i] << '\n';
    }

}