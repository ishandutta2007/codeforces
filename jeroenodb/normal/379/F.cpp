#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e6+6, oo = 1e9;
int par[mxN],d[mxN],jmp[mxN];
void add(int i) {
    int p = par[i];
    d[i]=1+d[p];
    if(d[p] - d[jmp[p]] == d[jmp[p]] - d[jmp[jmp[p]]]) jmp[i] = jmp[jmp[p]];
    else jmp[i] = p;
}
int jump(int a, int k) {
    int D = max(0,d[a]-k);
    while(d[a]>D) {
        if(d[jmp[a]]>=D) a = jmp[a];
        else a = par[a];
    }
    return a;
}
int lca(int a, int b) {
    if(d[a]<d[b]) swap(a,b);
    a = jump(a,d[a]-d[b]);
    while(a!=b) {
        if(jmp[a]!=jmp[b]) a=jmp[a],b=jmp[b];
        else a=par[a],b=par[b];
    }
    return a;
}
int dist(int a,int b) {
    return d[a]+d[b]-2*d[lca(a,b)];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; scanf("%d",&q);
    add(1),add(2),add(3);
    int at = 4;
    int res=2, a=1,b=2;
    while(q--) {
        int v; scanf("%d",&v),--v;
        par[at]=v;
        add(at++);
        par[at]=v;
        add(at);
        int tmp = dist(a,at);
        if(tmp>res) {
            res = tmp;
            b=at;
        } else {
            tmp = dist(b,at);
            if(tmp>res) {
                res=tmp;
                a=at;
            }
        }
        at++;
        printf("%d\n",res);
    }
}