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
const int mxN = 1e5+1;
 const ll oo = 1e18;
template<typename T> struct fenwick {
    int n;
    vector<T> fen;
    fenwick(){}
    fenwick(int nn) {
        fen.resize(nn+1);
        n = nn;
    }
    auto sum(int i) {
        T ans = 0;
        while(i) {
            ans+=fen[i];
            i&=i-1;
        }
        return ans;
    }
    auto query(int l, int r) {
        return sum(r+1)-sum(l);
    }
    void update(int i, T val) {
        ++i;
        while(i<=n) {
            fen[i]+=val;
            i+= i&(-i);
        }
    }
};
int ch(char c) {return c-'a';}
int main() {
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        string s,t; cin >> s >> t;
        ll ans = oo;
        ll used=0;
        vi nxt[26];
        for(int i=n-1;i>=0;--i) {
            nxt[ch(s[i])].push_back(i);
        }
        fenwick<int> fen(n+2);
        for(int i=0;i<n;++i) fen.update(i,1);
        for(int i=0;i<n;++i) {
            // try making smaller
            int k = 1e9;
            for(int j=0;j<ch(t[i]);++j) if(!nxt[j].empty()) {
                int cur = nxt[j].back();
                k = min(cur,k);
                int need = fen.query(0,cur-1);
                ans = min(ans,used+need);
            }
            auto c = ch(t[i]);
            if(nxt[c].empty()) break;
            int j = nxt[ch(t[i])].back();
            if(j>k) break;
            nxt[ch(t[i])].pop_back();
            fen.update(j,-1);
            used+=fen.query(0,j);
            
        }
        if(ans==oo) ans=-1;
        cout << ans << '\n';
    }
}