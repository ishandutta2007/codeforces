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
int height;
vector<string> rec(int k) {
    int mine = (1<<(height-k))+1;
    if(k==1) {
        return {{char(mine)}};
    }
    auto res = rec(k-1);
    vector<string> ans;
    for(auto i : res) for(auto j : res) {
        auto ii = i;
        *min_element(all(ii))=mine;
        auto jj = j;
        *min_element(all(jj))=mine;
        ans.push_back(i+jj);
        ans.push_back(ii+j);
    }
    return ans;
}
int main() {
    int k,A,h; cin >> k >> A >> h;
    mint H = h;
    int n = 1<<(k);
    height = k;
    vector<mint> pw(n*2,1);
    for(int i=1;i<n*2;++i) {
        pw[i]=pw[i-1]*A;
    }
    // make all trees
    
    vector<string> loses = rec(k);

    auto wins = loses;
    for(auto& win : wins) *find(all(win),char(2))=1;
    unordered_map<int,string> mpwin,mplose;
    auto get = [&](string& s, int st) {
        mint res=0;
        for(int i=0;i<(int)s.size();++i) {
            res+= pw[s[i]]*(i+st);
        }
        return res;
    };
    for(auto lose : loses) {
        mplose[get(lose,1).d]=lose;
    }
    for(auto win : wins) {
        mpwin[get(win,1).d]=win;
    } 
    cerr << "Done\n";
    for(auto lose : loses) {
        mint want = H-get(lose,1+n/2);
        if(mpwin.count(want.d)) {
            auto tmp =  mpwin[want.d]+lose;
            debug(get(tmp,1));
            cout << vi(all(tmp)) << '\n';
            exit(0);
        }
    } 
    for(auto win : wins) {
        mint want = H-get(win,1+n/2);
        if(mplose.count(want.d)) {
            auto tmp = mplose[want.d]+win;
            debug(get(tmp,1));
            cout << vi(all(tmp)) << '\n';
            exit(0);
        }
    }

    cout << "-1\n";


    

}