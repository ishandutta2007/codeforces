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
// const int store=1e6 + 1;
// bitset<store> sieve={};
// int factor[store] = {},cnt[store];
// void makesieve() {
//     for(int i = 2; i < store;++i) {
//         if(!sieve[i]) {
//             for(int j = i;j<store;j+=i) {
//                 if(!sieve[j]) {
//                     factor[j] = i;
//                     sieve[j] = true;
//                 }
//             }
//         }
//     }
//     for(int i=2;i<store;++i) {
//         cnt[i]=cnt[i/factor[i]]+1;
//     }
// }
// void print(int n) {
//     map<int,int> res;
//     while(n>1) {
//         res[factor[n]]++;
//         n/=factor[n];
//     }
//     cout << res << '\n';
// }
mint solve(vi v, int n) {
    v.insert(v.begin(),1);
    int m = v.size();
    for(int i=1;i<m;++i) v[i]*=v[i-1];
    vi cnt(m);
    for(int i=1;i<=n;++i) {
        int lo=0,hi=m-1;
        while(lo<hi) {
            int mid = (lo+hi+1)/2;
            if(i%v[mid]==0) lo=mid;
            else hi = mid-1;
        }
        cnt[lo]++;
    }
    vi pref(m+1);
    for(int i=m-1;i>=0;--i) {
        pref[i]=cnt[i]+pref[i+1];
    }
    mint dp[2][20] = {};
    dp[0][m-1]=1;
    for(int i=1;i<n;++i) {
        auto old = dp[(i-1)%2],cur = dp[i%2];
        fill(cur,cur+m,0);
        for(int j=0;j<m;++j) {
            if(j<m-1) cur[j]+=old[j+1]*cnt[j];
            if(pref[j]>i) cur[j]+=old[j]*(pref[j]-i);
        }
    }
    return dp[(n-1)%2][0];
}
int main() {
    int n; cin >> n;
    mint res=0;
    int j=__lg(n);
    vi a(j,2);
    res+=solve(a,n);
    if(3<<(j-1) <=n) {
        a.back()=3;
        do {
            res+=solve(a,n);
        } while(next_permutation(all(a)));
    }
    cout << res << '\n';


}