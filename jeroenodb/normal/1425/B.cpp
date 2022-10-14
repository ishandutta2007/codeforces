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
const long long MD = 1e9+7;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {}
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
struct DSU{
    vector<int> sz,parent;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        iota(all(parent),0);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        sz[a]+=sz[b];
        parent[b] = a;
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        return pa!=pb;
    }
    int find(int a) {
        if(a==parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
};
const int mxN = 4000;
struct DP {
    mint data[3][mxN*2+1] = {};
    mint *dp, *tmp, *dp2;
    DP() {
        dp=data[0]+mxN;
        tmp=data[1]+mxN;
        dp[0]=1;
        dp2 = data[2]+mxN;
        dp2[0]=1;
    }
    void add(int c) {
        fill(tmp-mxN,tmp+mxN+1,0);
        for(int i=-mxN;i<=mxN;++i) {
            tmp[i]+=dp[i];
            if(i+c<=mxN) tmp[i]+=dp[i+c];
            if(i-c>=-mxN) tmp[i]+=dp[i-c];
        }
        swap(tmp,dp);
        fill(tmp-mxN,tmp+mxN+1,0);
        for(int i=-mxN;i<=mxN;++i) {
            if(i+c<=mxN) tmp[i]+=dp2[i+c];
            if(i-c>=-mxN) tmp[i]+=dp2[i-c];
        }
        swap(tmp,dp2);
        // debug(vector<mint>(dp-mxN,dp+mxN+1));
        // debug(vector<mint>(dp2-mxN,dp2+mxN+1));
    }
    void remove(int c) {
        fill(tmp-mxN,tmp+mxN+1,0);
        for(int i=-mxN;i<=mxN;++i) {
            if(i-c>=-mxN) {
                tmp[i]=dp[i-c]; // -tmp[i]
                if(i-c>=-mxN) tmp[i]-=tmp[i-c];
                if(i-2*c>=-mxN) tmp[i]-=tmp[i-2*c];
            }
        }
        swap(tmp,dp);
        fill(tmp-mxN,tmp+mxN+1,0);
        for(int i=-mxN;i<=mxN;++i) {
            if(i-c>=-mxN) {
                tmp[i]=dp2[i-c]; // -tmp[i]
                if(i-2*c>=-mxN) tmp[i]-=tmp[i-2*c];
            }
        }
        swap(dp2,tmp);
        // debug(vector<mint>(dp-mxN,dp+mxN+1));
        // debug(vector<mint>(dp2-mxN,dp2+mxN+1));
    }
};
int main() {
    int n,m; cin >> n >> m;
    vector<pi> cycles;
    {
        // calculate cycles
        DSU dsu(n);
        for(int i=0;i<m;++i) {
            int u,v; cin >> u >> v;
            if(u>v) swap(u,v);
            --u,--v;
            if(u!=0) {
                dsu.unite(u,v);
            }
        }
        map<int,int> cnt;
        for(int i=1;i<n;++i) {
            if(dsu.find(i)==i) {
                cnt[dsu.sz[i]+1]++;
            }
        }
        cycles = vector<pi>(all(cnt));
    }
    // found cycles
    int k = cycles.size();
    DP dp;
    
        // subset sums to calculate it
    for(int i=0;i<k;++i) {
        auto [len,cnt] = cycles[i];
        for(int j=0;j<cnt;++j) {
            dp.add(len);
        }
    }
    mint ans = dp.dp2[0];
    for(int i=0;i<k;++i) {
        auto& [len,cnt] = cycles[i];
        dp.remove(len);
        // // 1 sliert
        // for(int dif=1;dif<len;++dif) {
        //     ans+=dp.dp[dif]*cnt*4;
        // }
        // 2 slierten
        for(int dif=1;dif<len;++dif) {
            ans+=dp.dp[dif- (len-dif)]*cnt*2;
            if(dif<len-1) ans+=dp.dp[dif- (len-dif-1)]*cnt*2;
        }
        // volledig ingevuld
        ans+=dp.dp2[len-1]*cnt*4;
        // // 2 slierten in verschillende cykels.
        // for(int j=i;j<k;++j) {
        //     if(i==j and cnt==1) continue;
        //     auto [len2,cnt2] = cycles[j];
        //     dp.remove(len2);
        //     int w = max(len,len2);
        //     mint coef = cnt*cnt2*8;
        //     if(i==j) coef = cnt*(cnt-1);
        //     for(int dif=-w;dif<=w;++dif) {
        //         mint num = max(0, min(len2,len+dif)-max(1,1+dif));
        //         ans+=dp.dp[dif]*num*coef;
        //     }
        //     dp.add(len2);
        // }
        dp.add(len);
    }
    cout << ans << '\n';

}