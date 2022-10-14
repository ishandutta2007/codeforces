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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<array<int,5>> a(n);
        for(auto& v : a) for(auto& i : v) {
            cin >> i;
        }
        int cand=0;
        auto better = [&](int i, int j) {
            int cnt=0;
            for(int k=0;k<5;++k) {
                if(a[i][k]<a[j][k]) cnt++;
            }
            return cnt>=3;
        };
        for(int i=0;i<n;++i) {
            if(better(i,cand)) cand=i;
        }
        bool good= true;
        for(int i=0;i<n;++i) {
            if(i!=cand and !better(cand,i)) {
                cout << "-1\n";
                good=false;
                break;
            }
        }
        if(good) cout << cand+1 << '\n';
    }
}