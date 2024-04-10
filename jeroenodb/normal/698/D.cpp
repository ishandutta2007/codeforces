#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "geodeb.h"
#endif
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
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p1;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
bool lexo(pt a, pt b) {
    return a.X<b.X or (a.X==b.X and a.Y > b.Y);
}
pt o; // origin
bool equivalent(const pt& a, const pt& b) {
    return lexo(o,a)==lexo(o,b) and ccw(o,a,b)==0;
}
bool polarcomp(const pt& a, const pt& b) {
    bool lex1 = lexo(o,a), lex2 = lexo(o,b);
    if(lex1!=lex2) return lex1<lex2;
    auto tmp = ccw(o,a,b);
    if(tmp==0) return norm(a-o)<norm(b-o);
    return tmp>0;
}
struct myset {
    array<short,8> mys;
    char sz=0;
    int count(short i) const {
       return ::count(mys.begin(),mys.begin()+sz,short(i));
    }
    int size() {
        return sz;
    }
    void insert(short i) {
        if(count(i)) return;
        if(sz==8) return;
        mys[sz++]=i;
    }
    void erase(short i) {
        int j = find(mys.begin(),mys.begin()+sz,i)-mys.begin();
        if(j!=sz) {
            swap(mys[j],mys[--sz]);
        }
    }
};
struct polarsortDS {
    vi rank, equiv, ord;
    polarsortDS(){}
    polarsortDS(pt stone, const vector<pt>& pts) {
        // GD_LAYER();
        // GD_POINT(stone.X,stone.Y,"blue");
        int n = pts.size();
        ord.resize(n); iota(all(ord),0);
        o=stone;
        sort(all(ord),[&](int i, int j){return polarcomp(pts[i],pts[j]);});
        rank.resize(n);
        for(int i=0;i<n;++i) rank[ord[i]]=i;
        equiv.resize(n);
        for(int i=1;i<n;++i) {
            equiv[i] = equiv[i-1] + !equivalent(pts[ord[i-1]],pts[ord[i]]);
        }
        // for(int i=0;i<n;++i) {
        //     int j = ord[i];
        //     GD_PAUSE();
        //     GD_POINT(pts[j].X,pts[j].Y,"red") << equiv[i];
        // }
    }
    myset addStoppers(int i,myset bad, const myset& shot) {
        i = rank[i]-1;
        while(bad.size()<8 and i>=0 and equiv[i]==equiv[i+1]) {
            if(!shot.count(ord[i])) bad.insert(ord[i]);
            --i;
        }
        return bad;
    }
};
vector<polarsortDS> ds;
int k,n;;
bool rec(myset bad, myset stones, myset shot) {
    if(bad.size()==0) return true;
    if(bad.size()>stones.size()) return false;
    for(int i=0;i<stones.size();++i) {
        int curS = stones.mys[i], curE = bad.mys[0];
        auto nwshot = shot;
        nwshot.insert(curE);
        auto nwbad = ds[curS].addStoppers(curE,bad,nwshot);
        nwbad.erase(curE);
        auto nw = stones;
        nw.erase(curS);
        if(rec(nwbad,nw,nwshot)) return true;
    }
    return false;
}
int main() {
    // GD_INIT("shootingpoints.html");
    cin >> k >> n;
    vector<pt> stones(k),pts(n);
    for(auto& i : stones) read(i);
    for(auto& i : pts) read(i);
    // need rank and equivalence classes per stone
    ds.resize(k);
    for(int i=0;i<k;++i) ds[i] = polarsortDS(stones[i],pts);
    myset allstones;
    for(int i=0;i<k;++i) allstones.insert(i);
    int ans=0;
    for(int i=0;i<n;++i) {
        myset b;
        b.insert(i);
        if(rec(b,allstones,myset())) {
            ans++;
        }
    }
    cout << ans << '\n';


}