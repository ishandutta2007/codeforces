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
int query(int i, int j, string s="XOR") {
    cout << s << ' ' << i+1 << ' ' << j+1 << endl;
    cin >> i;
    return i;
}
int xorquery(int i,int j) {
    return query(i,j);
}
int orquery(int i, int j){
    return query(i,j,"OR");
}
int andquery(int i, int j) {
    return query(i,j,"AND");
}
int main() {
    int n; cin >> n;
    array<int,3> best = {oo};
    map<int,int> mp;
    int lazy=0;
    mp[0] = 0;
    vi dif(n-1);
    for(int i=0;i<n-1;++i) {
        dif[i] = xorquery(i,i+1);
        lazy^=dif[i];
        if(mp.count(lazy)) {
            best = min(best,{0,mp[lazy],i+1});
        } 
        if(mp.count(lazy^1)) {
            best = min(best,{1,mp[lazy^1],i+1});
        }
        mp[lazy]=i+1;
    }
    vi a(n);
    a[best[1]] = orquery(best[1],best[2]);
    for(int i=best[1]-1;i>=0;--i) {
        a[i] = a[i+1]^dif[i];
    }
    for(int i=best[1];i+1<n;++i) {
        a[i+1] = a[i]^dif[i];
    }
    assert(best[0]<=1);
    if(best[0]==1) {
        int i=0;
        while(a[i]%2!=0) i++;
        int j = i+1;
        while(a[j]%2!=0) ++j;
        assert(j<n);
        if(orquery(i,j)%2!=0)
            for(auto& el : a) el^=1;
    }
    cout << "! " << a << endl;

}