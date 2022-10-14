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
typedef array<int,3> line;
bool concurrent(const array<line,3>& l) {
    ll ans=0;
    for(int i=0;i<3;++i) {
        int j = (i+1)%3, k = (i+2)%3;
        ans+=l[i][0]*((ll)l[j][1]*l[k][2]-(ll)l[k][1]*l[j][2]);
    }
    return ans==0;
}
bool parallel(const line& a, const line& b) {
    return ll(a[0])*b[1] == ll(b[0])*a[1];
}
vector<line> lines;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
int num;
bool search(vi ids, int k, bool expensive=false) {
    
    if(ids.empty()) {
        cout << "YES\n";
        cout << num << '\n';
        return true;
    }
    if(k==0) return false;
    if(ids.size()<=k) {
        cout << "YES\n";
        cout << num-k+ids.size() << '\n';
        for(auto i : ids) {
            cout << i+1 << " -1\n";
        }
        return true;
    }
    int n = ids.size();
    int lim = 20*k;
    if(expensive) lim = 30;
    for(int rep=0;rep<k*lim;++rep) {
        int i = rnd(0,n-1);
        int j;
        do {
            j = rnd(0,n-1);
        } while(i==j);
        i = ids[i],j = ids[j];
        line& a = lines[i], &b = lines[j];
        if(parallel(a,b)) continue;
        vi left;
        for(int l : ids) if(i!=l and j!=l and !concurrent({a,b,lines[l]})) {
            left.push_back(l);
        }
        int got = n-left.size();
        if(got*k >= n) {
            if(search(left,k-1,expensive or got<=k)) {
                cout << i+1 << ' ' << j+1 << '\n';
                return true;
            }
            if(got>k) break;
        }
    }
    return false;
}
int main() {
    // randomness:
    // 1/5'th to obtain first
    int n,k; cin >> n >> k;
    vi ids(n);
    iota(all(ids),0);
    lines.resize(n);
    for(auto& [a,b,c] : lines) {
        cin >> a >> b >> c;
    }
    num=k;
    auto tmp = search(ids,k);
    if(!tmp) {
        cout << "NO\n";
    }
}