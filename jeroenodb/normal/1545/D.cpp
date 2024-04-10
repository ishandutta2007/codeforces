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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,k; cin >> m >> k;
    vvi pos(k,vi(m));
    vector<ll> centroid, sq;
    for(auto& v : pos) {
        centroid.push_back(0);
        sq.push_back(0);
        for(auto& i : v) {
            cin >> i;
            centroid.back()+=i;
            sq.back()+=ll(i)*i;
        }
    }
    int at=1;
    ll sumv=0;
    ll sumvsq=0;
    {
    map<ll,int> cnt;
    for(int i=1;i<k;++i) {
        cnt[centroid[i]-centroid[i-1]]++;
    }
    for(auto [sv,c] : cnt) {
        if(c>2) sumv=sv;
    }
    }
    for(int i=1;i<k;++i) if(centroid[i]-centroid[i-1]!=sumv) {
        at=i;
        break;
    }
    bool f=0;
    if(at<=2) {
        f=1;
        reverse(all(pos));
        reverse(all(centroid));
        reverse(all(sq));
        sumv=-sumv;
        at = k-1-at;
    }
    sumvsq = (sq[0]-2*sq[1]+sq[2])/2;
    

    auto deltax = centroid[at] - (centroid[at-1]+sumv);
    auto cur = pos[at];

    for(int i=0;i<m;++i) {
        
        cur[i]-=deltax;
        ll cursq=0;
        for(auto& x : cur) cursq+=ll(x)*x;
        auto tmp = sq[at-2]-2*sq[at-1]+cursq;
        if(tmp==2*sumvsq) {
            cout << (f?k-1-at:at) << ' ' << cur[i] << endl;
            exit(0);
        }
        
        cur[i]+=deltax;

    }
    assert(false);
    
}