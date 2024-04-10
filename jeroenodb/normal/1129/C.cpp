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
const int mxN = 3000+1, oo = 1e9;
const long long MD = 1e9+7;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){};
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
const vector<string> bads = {"0011","0101","1110","1111"};
mint res[mxN];
struct trie{ 
    trie* tr[2] = {};
    trie* par= {};
    trie(){}
    char c;
    trie(trie* p, char f) {
        par=p;
        c=f;
        // calculate dp
        string s(1,c); s.reserve(4);
        for(int rep=0;rep<3;++rep) {
            dp+=p->dp;
            s.push_back(p->c);
            p=p->par;
            if(!p) return;
        }
        // now check if good
        for(auto& i : s) i+='0';
        reverse(all(s));
        if(count(all(bads),s)) return;
        dp+=p->dp;
    }
    mint dp=0;
};
trie rt;
void add(string t, int i) {
    auto at = &rt;
    for(auto c : t) {
        if(!at->tr[c]) {
            at->tr[c] = new trie(at,c);
            res[i]+=at->tr[c]->dp;
        }
        at = at->tr[c];
        
        ++i;
    }
}
int main() {
    int m; cin >> m;
    string s(m,'?');
    for(auto& i : s) cin >> i,i-='0';

    rt.dp=1;
    for(int i=0;i<m;++i) {
        add(s.substr(i),i);
    }
    mint ans=0;
    for(int i=0;i<m;++i) {
        ans+=res[i];
        cout << ans << '\n';
    }
    // need to do some pruning of substrings, so one substring isn't counted multiple times
    // Build stupid suffix trie, loop through all suffixes and in a trie give first occurrence id
    // DP on trie? Yeah, this is easy with parent pointers

}