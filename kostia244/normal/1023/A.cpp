//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("inline-small-functions")
//#pragma GCC optimize("-finline-small-functions")
//#pragma GCC optimize("-fexpensive-optimizations")
//#pragma GCC optimize("-funsafe-loop-optimizations")
//#pragma GCC optimize("inline-functions-called-once")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1e3 + 33, mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    int n, m;
    cin >> n >> m>> s >> t;
    if(s==t) {
    	return cout << "YES", 0;
    }
    int i = 0;
    while(i < s.size() && s[i]!='*') i++;
    if(i==s.size()) return cout << "NO", 0;
    int diff = m-n+1;
    if(diff<0) return cout << "NO", 0;
    s = s.substr(0, i) + t.substr(i, diff) + s.substr(i+1);
//    cout << s << " " << diff << "\n";
    if(s==t) {
    	return cout << "YES", 0;
    }
    cout << "NO";
}