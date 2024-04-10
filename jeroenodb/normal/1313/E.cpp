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
template<typename T> struct fenwick {
    int n;
    vector<T> fen;
    fenwick(){}
    fenwick(int nn) {
        fen.resize(nn+1);
        n = nn;
    }
    auto sum(int i) {
        ++i;
        T ans = 0;
        while(i) {
            ans+=fen[i];
            i&=i-1;
        }
        return ans;
    }
    void update(int i, T val) {
        ++i;
        while(i<=n) {
            fen[i]+=val;
            i+= i&(-i);
        }
    }
};
struct DS {
    fenwick<ll> f1,f2;
    int m;
    DS(int mm) : f1(mm+2),f2(mm+2), m(mm) {}
    void add(int a) {
        a=min(a,m-1);
        a=m-a;
        // range add on two things
        f1.update(a,1);
        f2.update(a,a-1);
    }
    ll query(int b) {
        b = min(b,m-1);
        return f1.sum(b)*b - f2.sum(b);

    }
};
vi zalgo(const string& s) {
    int n = s.size();
    vi z(n);
    for (int i=1,x=0,y=0;i<n;++i) {
        if(i<=y) z[i] = min(z[i-x], y-i+1);
		if(i+z[i]>y) {
            while(i+z[i]<n and s[i+z[i]]==s[z[i]]) {
                ++z[i];
            }
            x=i;
            y=z[i]+i-1;
		}
	}
    return z;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    string a,b,s; cin >> a >> b >> s;
    auto z1 = zalgo(s+'#'+a);
    z1.erase(z1.begin(),z1.begin()+m+1);
    reverse(all(s)), reverse(all(b));
    auto z2 = zalgo(s+'#'+b);
    z2.erase(z2.begin(),z2.begin()+m+1);
    reverse(all(z2));
    // add m-1, m-1, m-2, m-v to a multiset
    // suffix add
    // prefix query [1...m-1]
    DS ds(m);
    ll ans=0;
    for(auto i : z1) 
        ds.add(i);
    for(auto j : z2) 
        ans+=ds.query(j);
    ds = DS(m);
    for(int i=0;i<n;++i) {
        if(i>=m-1) 
            ds.add(z1[i-m+1]);
        ans-=ds.query(z2[i]);
    }
    ds = DS(m);
    for(int i=n-1;i>=0;--i) {
        ans-=ds.query(z2[i]);
        ds.add(z1[i]);
    }
    cout << ans << '\n';
}