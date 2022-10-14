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
    int n; cin >> n;
    if(n<=3) {
        cout << "0" << endl;
        exit(0);
    }
    pi best = {-oo,-oo};
    for(int k=1;k<=n;++k) {
        int score = n-k+1-(n+k-1)/k;
        if(score>best.first) best = {score,k};
    }
    int k = best.second;
    set<int> left;
    for(int i=1;i<=n;++i) {
        if(i%k!=1) left.insert(i);
    }
    for(int i=0;i<9000;++i) {
        if(left.size()<k) break;
        vi get;
        while(get.size()<k) {
            get.push_back(*left.begin());
            left.erase(left.begin());
        }
        cout << get.size() << ' ' << get << endl;
        int x; cin >> x;
        for(int j=0;j<k;++j) {
            int real = (x+j-1)%n + 1;
            if(real%k !=1) left.insert(real);
        }
    }
    cout << 0 << endl;
}