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
    int n; cin >> n;
    vi a(n);
    for(auto& i : a) {
        cin >> i;
        i%=3;
        if(i==2) i=1;
    }
    int cnt[2] = {};
    for(auto& i : a) cnt[i]++;
    // z=0
    if(cnt[0]<=n/2) {
        cout << 0 << '\n';
        int left=n/2;
        for(int i : a) {
            if(!i) cout << '0';
            else if(left) cout << '1',left--;
            else cout << '0';
        }
        exit(0);
    }
    // // z=1
    // if(cnt[0]==n/2) {
    //     cout << 1 << '\n';
    //     for(auto i : a) cout << i;
    //     cout << '\n';
    //     exit(0);
    // }
    // z=2
    if(cnt[1]<=n/2) {
        int left=n/2;
        cout << 2 << '\n';
        for(int i : a) {
            if(i) cout << '0';
            else if(left) cout << '1',left--;
            else cout << '0';
        }
        exit(0);
    }

    cout << "-1\n";

}