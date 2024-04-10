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

struct segtree {
    int ptwo;
    vector<ll> seg;
    segtree(){}
    segtree(int nn) {
        ptwo=1;
        while(ptwo<nn) 
            ptwo*=2;
        seg.assign(ptwo*2,0);
    }
    int find() {
        int i=1,r=ptwo*2-1, size=ptwo;
        ll got=0;
        while(i<ptwo) {
            auto g = gcd(got,gcd(seg[i*2+1],seg[r-size/2]));
            if(g!=1) {
                got=gcd(got,seg[i*2+1]);
                i=i*2;
                r-=size/2;
            } else i=i*2+1;
            size/=2;
        }
        return i-ptwo;
    }
    void update(int i, ll val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = val;
        for(i/=2;i>=1;i/=2) {
            seg[i] = gcd(seg[2*i],seg[2*i+1]);
        }
    }
};
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
int brute(vector<ll>& a) {
    int ans=1;
    for(int m=2;m<=2000;++m) {
        auto b = a;
        for(auto& i : b) i%=m;
        int cur=1;
        for(int i=1;i<a.size();++i) {
            if(b[i]==b[i-1]) {
                cur++;
            } else {
                cur=1;
            }
            ans = max(cur,ans);
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    // int t=1000;
    while(t--) {
        int n; cin >> n;
        // int n = rnd(1,5);
        segtree seg(n+1);
        int ans=1;
        vector<ll> a(n);
        for(auto& i : a) cin >> i;
        // for(auto& i : a) i=rnd(1,100);
        // int real = brute(a);
        for(int i=1;i<n;++i) {
            seg.update(i-1,abs(a[i]-a[i-1]));
            int j=seg.find();
            ans = max(ans,i-j+1);
        }
        cout << ans << '\n';
        // debug(a);
    
        // assert(real==ans);
    }
}