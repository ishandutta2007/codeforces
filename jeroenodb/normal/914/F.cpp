#pragma GCC optimize("O3")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int mxN = 1e5+1, oo = 1e9;
char s[mxN];
vector<array<int,26>> kmpi(const string& p) { // constructs PI function for pattern p
    int n = p.size();
    vector<array<int,26>> pi(n+1);
    pi[0][p[0]-'a']=1;
    int suf=0;
    for(int i=1;i<n;++i) {
        pi[i]=pi[suf];
        pi[i][p[i]-'a']=i+1;
        suf = pi[suf][p[i]-'a'];
    }
    pi[n] = pi[suf];
    return pi;
}
const int B = 6;
unordered_map<string,ordered_set> occ;
int KMP(const string& p, int l, int r) {
    int ans=0, len = p.size(), j =0;
    if(p.size()>B) {
        auto ss = s+l, ee = s+r+1;
        auto pi = kmpi(p);
        
        while(ss!=ee) {
            j=pi[j][*ss-'a'];
            ans+=j==len;
            ++ss;
        }

    } else {
        auto& v = occ[p];
        r-=len-1;
        if(r<l) return 0;
        return v.order_of_key(r+1)-v.order_of_key(l);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int n=0;
    for(auto& c : s) {
        if(!c) break;
        n++;
    }
    for(int len=1;len<=B;++len) for(int i=0;i+len<=n;++i) {
        occ[basic_string<char>(s+i,s+i+len)].insert(i);
    }
    
    int q; cin >> q;
    while(q--) {
        int tt; cin >> tt;
        if(tt==1) {
            int i; cin >> i;
            --i;
            char c; cin >> c;
            for(int j=i;j>=max(0,i-B+1);--j) {
                for(int len=i-j+1;len<=B;++len) {
                    if(j+len>n) break;
                    string t(s+j,s+j+len);
                    auto& v = occ[t];
                    if(v.size()==1) occ.erase(t);
                    else v.erase(j);
                }
            }
            s[i]=c;
            for(int j=i;j>=max(0,i-B+1);--j) {
                for(int len=i-j+1;len<=B;++len) {
                    if(j+len>n) break;
                    string t(s+j,s+j+len);
                    auto& v = occ[t];
                    v.insert(j);
                }
            }  
        } else {
            int l,r; cin >> l >> r;
            string y; cin >> y;
            cout << KMP(y,l-1,r-1) << '\n';
        }
    }


}