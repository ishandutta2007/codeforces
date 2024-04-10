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
const int mxN = 1e5+1, oo = 2e9;
typedef array<int,2> pt;
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
typedef array<pt,2> rect;
vector<rect> rs;
struct arrayLL {
    vi nxt,prv;
    int head;
    template<typename T> arrayLL(T l, T r) : nxt(r-l,-1),prv(r-l,-1) {
        head=*l;
        for(T i=l;i!=r and i+1!=r;++i) {
            nxt[*i]=*(i+1);
            prv[*(i+1)]=*i;
        }
    }
    struct iterator {
        arrayLL* mine = NULL;
        
        int i;
        int operator *() {
            return i;
        }
        operator bool()  {
            return !!mine;
        }
        bool operator==(const iterator& o) const {
            return mine==o.mine and i==o.i;
        }
        bool operator!=(const iterator& o) const {
        return !(*this==o);
        }
        void operator++() {
            i = mine->nxt[i];
        }

    };
    void erase(iterator it) { // makes it into own size 1 list, and delete from current list
        int at = it.i;
        if(prv[at]!=-1) nxt[prv[at]]=nxt[at];
        if(nxt[at]!=-1) prv[nxt[at]]=prv[at];
        nxt[at]=prv[at]=-1;
    }
    void concat(iterator a, iterator b) {
        if(!a.mine) return;
        if(!b.mine) return;
        int i = a.i, j = b.i;
        assert(nxt[i]==-1 and prv[j]==-1);
        nxt[i]=j;
        prv[j]=i;
    }
    iterator getIt(int i) {
        return iterator{this,i};
    }
    iterator begin() {
        return iterator{this,head};
    }
};
typedef arrayLL::iterator IT;
vector<arrayLL> vs;

bool rec(int n, array<IT,4> start) {
    if(n==1) return true;
    
    auto it = start;
    struct DS {
        int coord,side,mx=-oo;
        bool update(IT& it) {
            int sgn = side?-1:1;
            
            auto& r = rs[*(it)];
            ++it;
            if(mx!=-oo and mx <= sgn*r[side][coord]) 
                return true;
            mx = max(mx,sgn*r[!side][coord]);
            return false;
        }
        int split() {
            int sgn = side?-1:1;
            return sgn*mx + side;
        }
    };
    DS d[4] = {{0,0},{0,1},{1,0},{1,1}};
    array<IT,4>  m,e;
    for(int rep=0;rep<n;++rep) {
        for(int i=0;i<4;++i) {
            if(d[i].update(it[i])) {
                // for all lists
                auto left = start[i];
                vi v;
                for(int j=0;j<rep;++j) {
                    v.push_back(*left);
                    ++left;
                }
                for(auto x : v) {
                    for(int o=0;o<4;++o) {
                        auto curit = vs[o].getIt(x);
                        if(curit==start[o]) {
                            ++start[o];
                        }
                        vs[o].erase(curit);
                        if(!m[o]) m[o]=curit;
                        vs[o].concat(e[o],curit);
                        e[o] = curit;

                        // now need to disconnect this from the front
                        
                    }
                }
                return rec(n-rep,start) and rec(rep,m);
            }
        }
    }
    return false;


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    rs.resize(n);
    for(auto& r : rs) {
        for(auto& p : r) read(p);
    }
    vi v(n); iota(all(v),0);
    for(auto a : {0,1} ) {
        sort(all(v),[&](int i, int j) {return rs[i][0][a]< rs[j][0][a];});
        vs.emplace_back(all(v));
        sort(all(v),[&](int i, int j) {return rs[i][1][a]>rs[j][1][a];});
        vs.emplace_back(all(v));
    }
    array<IT,4> start;
    for(int i=0;i<4;++i) start[i] = vs[i].begin();
    cout << (rec(n,start)?"YES\n":"NO\n");
}