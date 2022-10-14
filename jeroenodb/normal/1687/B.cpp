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
    int n,m; cin >> n >> m;
    vi ws(m);
    auto query = [&](string s) {
        cout << "? " << s << endl;
        ll w; cin >> w;
        return w; // maximum spanning tree
    };
    
    for(int i=0;i<m;++i) {
        string s(m,'0');
        s[i]='1';
        ws[i]=query(s);
    }
    vi ord(m); iota(all(ord),0);
    sort(all(ord),[&](int i, int j) {return ws[i]<ws[j];});
    string s(m,'0');
    ll last=0;
    for(auto i : ord) {
        s[i]='1';
        auto cur = query(s);
        if(cur!=last+ws[i]) {
            s[i]='0';
        } else last+=ws[i];
    }
    cout << "! " << last << endl;
}