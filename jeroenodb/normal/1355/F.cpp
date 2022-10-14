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
const int store=1e5 + 1;
bitset<store> sieve={};
int factor[store] = {}, delers[store];
vector<vi> queries;
void makesieve() {
    ll cur=1;
    vi now;
    delers[1]=1;
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            if(cur<=oo/i) cur*=i, now.push_back(i);
            else queries.push_back(now), cur = i, now = {i};
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
        int at = i, f = factor[i],tmp=0;
        while(factor[at]==f) at/=f,tmp++;
        delers[i] = delers[at]*tmp;
    }
    queries.resize(22-5);
    // for(auto i : queries) cout << i << '\n';
}
int query(ll a) {
    cout << "? " << a << endl;
    cin >> a;
    return a;
}
void solve() {
    vi ps;
    for(auto v : queries) {
        ll q = accumulate(all(v),1LL,multiplies<ll>());
        auto a = query(q);
        for(auto i : v) if(a%i==0) ps.push_back(i);
    }
    int n = ps.size();
    int difs=1;
    for(int i=0;i<n;i+=2) {
        ll p = 1;
        while(ps[i]*p<=int(1e9)) 
            p*=ps[i];
        if(i<n-1) {
            ll q=1;
            while(ps[i+1]*q<=int(1e9)) q*=ps[i+1];
            p*=q;
        }
        auto res = query(p);
        int tmp=0;
        while(res%ps[i]==0) 
            tmp++,res/=ps[i];
        difs*=(tmp+1);
        tmp=0;
        if(i<n-1) {
            while(res%ps[i+1]==0) 
                tmp++,res/=ps[i+1];
            difs*=(tmp+1);
        }
    }
    cout << "! " << max(difs+7, difs*2) << '\n';
}
int main() {
    makesieve();
    int t; cin >> t;
    while(t--) solve();
}