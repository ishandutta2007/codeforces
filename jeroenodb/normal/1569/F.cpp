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
const int mxN = 12, oo = 1e9;
bool g[12][12], used[13];
ll ans=0;
int n=12,k;
int a[12];
bool pused[6];
bool goodr(int i=0, int d=0) {
    if(d==n-2) return g[a[i]][a[i+1]];
    for(int to=0;to<n;to+=2) if(!pused[to]) {
        if((g[a[i]][a[to]] and g[a[i+1]][a[to+1]]) or (g[a[i]][a[to+1]] and g[a[i+1]][a[to]])) {
            pused[to]=true;
            if(goodr(to,d+2)) {
                pused[to]=false;
                return true;
            }
            pused[to]=false;
        }
    }
    return false;
}
bool good() {
    for(int i=0;i<n;i+=2) {
        pused[i]=true;
        if(goodr(i)) {
            pused[i]=false;
            return true;
        }
        pused[i]=false;

    }
    return false;
}
set<array<char,12>> s;
int eq=0;
array<char,12> equiv,mp,reale;
void normalize() {
    fill(all(mp),-1);
    int t=0;
    for(int i=0;i<n;++i) {
        if(mp[equiv[i]]==-1) mp[equiv[i]]=t++;
        reale[i]=mp[equiv[i]];
    }
}
void rec2(int i=0) {
    if(i==n) {
        normalize();
        if(eq>k) return;
        if(!s.count(reale)) {
            // count this
            int cur=1;
            for(int j=k-eq+1;j<=k;++j) {
                cur*=j;
            }
            ans+=cur;
            s.insert(reale);
        }
        return;
    }
    equiv[a[i]]=eq;
    equiv[a[i+1]]=eq;
    eq++;
    rec2(i+2);
    eq--;
    for(int j=0;j<eq;++j) {
        equiv[a[i]]=j;
        equiv[a[i+1]]=j;
        rec2(i+2);
    }
}
void rec(int i, int d=0) {
    while(used[i]) ++i;
    if(i==n) {
        // check if can be hamiltonian path
        if(good()) {
            // find all superequivalences
            rec2();
        }
        return;
    }
    used[i]=true;
    for(int j=i+1;j<n;++j) if(!used[j]) {
        used[j]=true;
        a[d]=i;
        a[d+1]=j;
        rec(i+1,d+2);
        used[j]=false;
    }
    used[i]=false;
}

int main() {
    int m; cin >> n >> m >> k;
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v,--u,--v;
        g[u][v]=true;
        g[v][u]=true;
    }
    rec(0);
    cout << ans << '\n';
}