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
const int mxN = 1e5+1, oo = 1e9;
typedef complex<int> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
const int N = 999;
bool inside(pt p) {
    return 0<p.X and p.X<=N and 1<=p.Y and p.Y<=N;
}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int sgn(int a) {
    return (a>0)-(a<0);
}
bool online(pt p) {
    return min(p.X,p.Y)==0;
}
const int ROOKS = 666;
const pt mid = pt{(N+1)/2,(N+1)/2};
pt kingmoveto(pt p) {
    return pt{sgn(p.X), sgn(p.Y)};
}
int main() {
    array<pt,ROOKS> rs;
    pt p; read(p);
    for(auto& i : rs) {
        read(i);
    }
    std::function<void(pt,bool)> query = [&](pt nwp, bool trygood) {
        for(auto r : rs) {
            if(nwp==r) {
                if(!trygood) return;
                for(auto d : dir8) {
                    nwp = d+p;
                    for(auto rr : rs) {
                        if(online(rr-nwp)) 
                            query(nwp,false);
                    }
                }
            }
        };
        p=nwp;
        cout << p.X << ' ' << p.Y << endl;
        int k; pt q; cin >> k;
        read(q);
        if(k==-1) 
            exit(0);
        rs[k-1]=q;
    };
    while(p!=mid) {
        // move to middle
        query(p + kingmoveto(mid-p),true);
    }
    map<pi,int> got;
    for(int i : {-1,1}) for(int j : {-1,1}) got[{i,j}]=0;
    for(auto r : rs) {
        auto to = (kingmoveto(r-mid));
        got[{to.X,to.Y}]++;
    }
    auto it = min_element(all(got),[&](pair<pi,int> a, pair<pi,int> b) {return a.second<b.second;});
    pt to = -pt{it->first.first, it->first.second};
    while(true) {
        query(p+to,true);
    }

    
}