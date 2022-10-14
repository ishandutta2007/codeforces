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
const long long MD = 1e9+7;
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
void solve() {
    
    int n; cin >> n;
    vi p(n);
    for(auto& i : p) cin >> i,--i;
    vector<bool> vis(n);
    array<int,4> cnt = {};
    for(int i=0;i<n;++i) if(!vis[i]) {
        int at = i,cyc=0;
        while(!vis[at]) {
            vis[at]=true;
            at=p[at];
            cyc++;
        }
        if(cyc==1) cnt[3]++;
        else cnt[cyc%3]++;
    }
    int cmps = (n+2)/3;
    int ans=oo;
    bool four=0;
    auto greedy = [&](array<int,4> a, int comps=0, int ops=0) {
        a[1]+=a[3];
        a[3]=0;
        int dif = min(a[1],a[2]);
        comps+=dif;
        ops+=dif;
        a[1]-=dif,a[2]-=dif;
        ops+=(a[1]+a[2])/3*2;
        comps+=(a[1]+a[2])/3;
        comps+=a[0];
        int waste = abs(cmps-comps);
        if(four) waste = abs(cmps-1-comps);
        ans = min(ans,waste+ops);
    };
    
    auto oneTwo = [&](array<int,4> a, int comps=0, int ops=0)  {
        a[1]+=a[3];
        a[3]=0;
        if(a[2]) {
            auto b = a;
            b[2]--;
            greedy(b,1+comps,ops);
        }
        if(a[1]>=2) {
            auto b = a;
            b[1]-=2;
            greedy(b,1+comps,ops+1);
        }
    };
    if(n%3==0) {
        greedy(cnt);
    } else if(n%3==2) {
        oneTwo(cnt,0);
    } else if(n%3==1) { // two twos
        
        four=1;
        if(cnt[1]) {
            auto b = cnt;
            b[1]--;
            greedy(b,1,0);
        }
        if(cnt[2]>=2) {
            auto b = cnt;
            b[2]-=2;
            greedy(b,1,1);
        }
        if(cnt[3] and cnt[0]) {
            auto b=  cnt;
            b[3]--;
            b[0]--;
            greedy(b,1,1);
        }
        four=0;
        // make one 2, and reduce to case with one two
        if(cnt[1]) {
            auto b = cnt;
            b[1]--;
            b[2]++;
            oneTwo(b,1,1);
        }
        if(cnt[3]>=2) {
            auto b = cnt;
            b[3]-=2;
            oneTwo(b,1,1);
        }
        if(cnt[2]) {
            auto b=  cnt;
            b[2]-=1;
            oneTwo(b,1,0);
        }

    }
    mint res=1;
    if(n%3==0) res=mint(3)^n/3;
    else if(n%3==1) res = (mint(3)^(n/3 - 1))*2*2;
    else if(n%3==2) res = (mint(3)^(n/3))*2;
    cout <<  res  << ' ' << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}