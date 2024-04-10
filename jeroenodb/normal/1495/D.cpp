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
const long long MD = 998244353;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){
        if(d<0) d+=MOD;
    };
    friend mdint& operator+=(mdint& a, const mdint& o) {
        a.d+=o.d; if(a.d>=MOD) a.d-=MOD;
        return a;
    }
    friend mdint& operator-=(mdint& a, const mdint& o) {
        a.d-=o.d; if(a.d<0) a.d+=MOD;
        return a;
    }
    friend mdint& operator*=(mdint& a, const mdint& o) {
        return a = mdint((ll)a.d*o.d);
    }
    mdint operator*(const mdint& o) const {
        mdint res = *this;
        res*=o;
        return res;
    }
    mdint operator+(const mdint& o) const {
        mdint res = *this;
        res+=o;
        return res;
    }
    mdint operator-(const mdint& o) const {
        mdint res = *this;
        res-=o;
        return res;
    }
    mdint operator^(long long b) const {
        mdint tmp = 1;
        mdint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    friend mdint operator/=(mdint& a, const mdint& o) {
        a *= (o^(MOD-2));
        return a;
    }
    mdint operator/(const mdint& o) {
        mdint res = *this;
        res/=o;
        return res;
    }
    bool operator==(const mdint& o) { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint<MD>;
const int mxN = 400+1, oo = 1e9;
int d[mxN][mxN],ans[mxN][mxN];
vi adj[mxN];
int n;
void bfs(int* dd, int s) {
    fill(dd,dd+n,oo);
    dd[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        auto at = q.front();q.pop();
        for(auto to : adj[at]) if(dd[to]==oo) {
            q.push(to);
            dd[to] =dd[at]+1;
        }
    }
}
mint solve(int i, int j) {
    int total = d[i][j];
    vector<bool> path(total+1);
    mint res=1;
    for(int k=0;k<n;++k) {
        if(d[i][k]+d[k][j]==total) {
            if(path[d[i][k]]) return 0;
            path[d[i][k]]=true;
        } else {
            int cur=0;
            for(auto to : adj[k]) {
                if(d[i][k]==d[i][to]+1 and d[j][k]==d[j][to]+1) {
                    cur++;
                }
            }
            res*=cur;
        }
    }
    return res;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin >> n >> m;
    while(m--) {
        int a,b; cin >> a >> b,--a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;++i) bfs(d[i],i);
    for(int i=0;i<n;++i) {
        for(int j=i;j<n;++j) {
            ans[j][i] = ans[i][j]= solve(i,j).d;
        } 
    }
    for(int i=0;i<n;++i) cout << vi(ans[i],ans[i]+n) << '\n';
}