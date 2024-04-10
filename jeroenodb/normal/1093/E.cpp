#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
#define sz(x) int(size(x))
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
struct FT {
vector<int> s;
FT(int n) : s(n) {}
    void update(int pos, int dif) { // a[ pos ] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    int query(int pos) { // sum of value/s in [0 , pos)
        int res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(int sum) {// min pos st sum of [0 , pos ] >= sum
        // Returns n i f no sum is >= sum, or 1 i f empty sum is .
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
        if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
            pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};
struct FT2 {
    vector<vi> ys; vector<FT> ft;
    FT2(int limx) : ys(limx) {}
    void fakeUpdate(int x, int y) {
        for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
    }
    void init() {
        for (vi& v : ys) sort(all(v)), v.erase(unique(all(v)),v.end()), ft.emplace_back(sz(v));
    }
    int ind(int x, int y) {
        return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
    void update(int x, int y, ll dif) {
        for (; x < sz(ys); x |= x + 1)
            ft[x].update(ind(x, y), dif);
    }
    int query(int x, int y) {
        int sum = 0;
        for (; x; x &= x - 1)
            sum += ft[x-1].query(ind(x-1, y));
        return sum;
    }
    int query(int l,int r,int a, int b) {
        r++,b++;
        return query(r,b)-query(l,b)-query(r,a) + query(l,a);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;

    vi arev(n), c(n);
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        arev[a-1] = i;
    }
    for(int i=0;i<n;++i) {
        cin >> c[i];
        c[i] = arev[c[i]-1];
    }
    FT2 fenw(n+3);
    for(int i=0;i<n;++i) {
        fenw.fakeUpdate(i, c[i]);
    }
    vector<array<int,4>> qs;
    vi cc = c; // keep copy of original
    while(q--) {
        int t; cin >> t;
        if(t==1) {
            int l,r,a,b; cin >> l >> r >> a >> b;
            --l,--r,--a,--b;
            qs.push_back({a,b,l,r});
        } else {
            int x,y; cin >> x >> y,--x,--y;
            qs.push_back({-1,x,y});
            fenw.fakeUpdate(x,c[x]);
            fenw.fakeUpdate(y,c[y]);
            swap(c[x],c[y]);
            fenw.fakeUpdate(x,c[x]);
            fenw.fakeUpdate(y,c[y]);
        }
    }
    fenw.init();
    c=cc;
    for(int i=0;i<n;++i) {
        fenw.update(i, c[i],1);
    }
    for(auto [l,r,a,b] : qs) {
        if(l==-1) {
            int x=r,y=a;
            fenw.update(x,c[x],-1);
            fenw.update(y,c[y],-1);
            swap(c[x],c[y]);
            fenw.update(x,c[x],1);
            fenw.update(y,c[y],1);

        } else {
            cout << fenw.query(l,r,a,b) << '\n';
        }
    }


}