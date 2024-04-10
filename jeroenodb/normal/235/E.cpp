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
const int store=2e3 + 1;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class K,class V> using ht = gp_hash_table<
		K,
		V,
		hash<K>,
		equal_to<K>,
		direct_mask_range_hashing<>,
		linear_probe_fn<>,
		hash_standard_resize_policy<
			hash_exponential_size_policy<>,
			hash_load_check_resize_trigger<>,
			true
		>
>;
bitset<store> sieve={};
vi ps;
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            ps.push_back(i);
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    sieve[j] = true;
                }
            }
        }
    }
}
unordered_map<ll,unsigned> dp[2001];
ll cnt=0;
typedef array<short,2> ar2;
unsigned solve(unsigned a, unsigned b, unsigned c, int pid) {
    if(pid==-1) {
        return 1;
    }
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);
    cnt++;

    auto p = ps[pid];
    auto tmp = b*2001LL*2001+c*2001+a;
    auto it = dp[pid].find(tmp);
    if(it!=dp[pid].end()) return it->second;
    auto& res = dp[pid][tmp];
    for(int i=0,toa=a;toa;toa/=p,++i) {
        for(int j=0, tob=b;tob;tob/=p,++j) {
            for(int k=0, toc=c;toc;toc/=p,++k) {
                res+=unsigned(i+j+k+1)*solve(toa,tob,toc,pid-1);
            }
        }
    }
    return res;
}
int main() {
    makesieve();
    debug(ps.size());
    int a,b,c; cin >> a >> b >> c;
    cout << (solve(a,b,c,ps.size()-1)&((1<<30) -1)) << '\n';
    debug(cnt);

}