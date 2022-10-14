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
const long long MOD = 1e9+7;
class mint {
public:
    int d;
    mint () {d=0;}
    mint (long long _d) : d(_d%MOD){};
    mint operator*(const mint& o) const {
        return ((ll)d*o.d)%MOD;
    }
    mint operator+(const mint& o) const {
        long long tmp = d+o.d;
        if(tmp>=MOD) tmp-=MOD;
        return tmp;
    }
    mint operator-(const mint& o) const {
        long long tmp = d-o.d;
        if(tmp<0) tmp+=MOD;
        return tmp;
    }
    mint operator^(long long b) const {
        mint tmp = 1;
        mint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    mint operator/(const mint& o) {
        return *this * (o^(MOD-2));
    }
    bool operator==(const mint& o) {
        return d==o.d;
    }
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }
};
pair<int,mint> calc(ll a, ll b, ll both) {
    if(both>=2 or (a and b) or ((a or b) and both)) {
        // two is possible
        return {2, both*(a+b) + a*b + both*(both-1)};
    } else if(a or b or both) {
        return {1, a+b+both*2};
    } return {0,1};
}
int main() {
    int n,m; cin >> n >> m;
    vi s(n); for(auto& i : s) cin >> i;
    vvi where(n+1);
    for(int i=0;i<n;++i) where[s[i]].push_back(i);
    vi a,b,fs;
    for(int i=0;i<m;++i) {
        int f,h;
        cin >> f >> h;
        int sz = where[f].size();
        if(h<=sz) {
            a.push_back(where[f][h-1]);
            b.push_back(where[f][sz-h]);
            fs.push_back(f);
        }
    }
    m=a.size();
    mint ans = 0;
    int best=-1;
    // special case: all right side
    a.push_back(-1);
    fs.push_back(-1);
    vector<array<int,3>> have(n+1);
    for(int i=0;i<=m;++i) {

        fill(all(have),array<int,3>{});
        int specialf=fs[i], split = a[i];
        if(specialf!=-1) have[specialf][0]++;
        for(int j=0;j<m;++j) {
            if(fs[j]==specialf) {
                if(a[j]!=split and split<b[j]) have[fs[j]][1]++;
                continue;
            }
            if(a[j]<=split) {
                if(split<b[j]) {
                    have[fs[j]][2]++;
                } else have[fs[j]][0]++;
            } else if(split<b[j]) have[fs[j]][1]++;
        }
        int sleeping=0;
        mint cur=1;
        for(auto [l,r,both]:have) {
            auto [get,sm] = calc(l,r,both);
            cur=cur*sm;
            sleeping+=get;
        }
        if(sleeping>best) best=sleeping,ans=0;
        if(sleeping==best) {
            ans+=cur;
        }
    }
    cout << best << ' ' << ans.d << '\n';
}