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
bool inside(pt p) {
    return p.X>0 and p.X<=8 and p.Y>0 and p.Y<=8;
}
const pt dir8[] = {{0,1}, {0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
string moves[] = {"Right", "Left", "Up", "Down", "Down-Right", "Down-Left", "Up-Left", "Up-Right", "Done"};
typedef array<bitset<9>,9> state;
pt q;
bool noQ(pt to, pt qq) {
    return qq.X!=to.X and qq.Y!=to.Y and qq.X-qq.Y!=to.X-to.Y and qq.X+qq.Y!=to.X+to.Y;
}
state transition(state old, pt qq, pt d) {
    state nw = {};
    for(int i=1;i<=8;++i) for(int j=1;j<=8;++j) if(old[i][j]) {
        auto to = pt{i,j}+d;
        if(inside(to) and noQ(to,qq)) {
            nw[to.X][to.Y]=1;
        }
    }
    return nw;
}
state input(state old) {
    string s; cin >> s;
    auto id = find(moves,moves+9,s)-moves;
    if(id==8) return {};
    return transition(old,q, dir8[id]);
}
int count(state st) {
    int res=0;
    for(int i=1;i<=8;++i) res+=st[i].count();
    return res;
}
void print(pt p) {
    cout << p.X << ' ' << p.Y << endl;
}
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
void solve() {
    q = {5,5};
    state s = {};
    for(int i=1;i<=8;++i) for(int j=1;j<=8;++j) s[i][j]=1;
    print(q);
    while(true) {
        s = input(s);
        if(count(s)==0) break;
        struct el {
            int c;
            pt qto;
            bool operator<(const el& o) {
                return c<o.c;
            }
        };
        vector<el> cand;
        for(int i=1;i<=8;++i) for(int j=1;j<=8;++j) if(!noQ(q,{i,j})) {
            pt to = {i,j};
            if(to==q) continue;
            int worst=0;
            for(auto d : dir8) {
                worst=max(worst,count(transition(s,to,d)));
            }
            cand.push_back({worst,to});
        }
        sort(all(cand));
        int mn = cand[0].c;
        int k = partition(all(cand),[&](auto e) {return e.c==mn;})-cand.begin();
        auto take = cand[rnd(0,rnd(0,k-1))];
        q = take.qto;
        print(q);
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}