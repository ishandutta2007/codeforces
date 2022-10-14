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
vi a;
int q(int i) {
    if(a[i]!=-1) return a[i];
    cout << "? " << i+1 << endl;
    int ans; cin >> ans;
    return a[i] = ans;
}
int ans(int i) {
    cout << "! " << i+1 << endl;
    exit(0);
}
int main() {
    int n; cin >> n;
    a.assign(n,-1);
    for(int i : {0,1,n-2,n-1}) {
        q(i);
    }
    if(a[0]<a[1]) {
        ans(0);
    }
    if(a[n-2]>a[n-1]) {
        ans(n-1);
    }
    int l = 1, r = n-2;
    while(l<r) {
        int mid = (l+r)/2;
        if(q(mid) < q(mid+1)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    ans(l);
}