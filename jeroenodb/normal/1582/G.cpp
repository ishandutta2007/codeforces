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
const int store=1e6 + 1;
bitset<store> sieve={};
int factor[store] = {};
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
    }
}
struct DS {
    map<int,int> mp;
    int negs=0;
    int size(){return mp.size();}
    DS(int i, int sgn=1) {
        while(i>1) {
            int f = factor[i];
            int tmp = 0;
            while(factor[i]==f) {
                i/=f,tmp++;
            }
            if(sgn==-1) negs++;
            mp[f]=tmp*sgn;
        }
    }
    void merge(DS& o) {
        if(size()<o.size()) swap(mp,o.mp);
        negs = max(negs,o.negs);
        for(auto [i,cnt] : o.mp) {
            
            auto& cur = mp[i];
            bool transition=cur<0 or cnt<0;
            cur+=cnt;
            transition &= cur>=0;
            if(transition) negs--;
            
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    makesieve();
    int n; cin >> n;
    vector<DS> v;
    vi a(n); for(auto& i : a) cin >> i;
    string b; cin >> b;
    ll ans = 0;
    for(int i=0;i<n;++i) {
        v.push_back(DS(a[i], b[i]=='*'?1:-1));
        while(!v.empty() and v.back().negs) {
            if(v.size()>1)  {
                auto& cur = v[v.size()-2];
                cur.merge(v.back());
            }
            v.pop_back();
        }
        ans+=v.size();
    }
    cout << ans << '\n';
}