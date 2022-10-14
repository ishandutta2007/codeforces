#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//	freopen("in", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[100001], sdp[100001], ldp[100001], b[100001], le = 0, ans;
bool add;
string s, t;
int main() {
	doin();
	cin >> s >> t;
    memset(dp, 0, sizeof dp);
    dp[0] = sdp[0] = 0;
    int i = 0, j = -1;
    b[0] = -1;
    while(i < t.size()) {
        while(j != -1 && t[i] != t[j]) j = b[j];
        i++, j++;
        b[i] = j;
    }
    i = 0, j = 0;
    while(i < s.size()) {
        while(j != -1 && s[i] != t[j]) j = b[j];
        i++, j++;
        if(j == t.size())
            j = b[j], le = i-t.size()+1;
        (dp[i] = le > 0 ? sdp[le-1]+le: 0) %= mod;
        (ldp[i] = ldp[i-1] + dp[i])%=mod;
        (sdp[i] = sdp[i-1]+ldp[i])%=mod;
    }
    cout << ldp[s.size()];
    return 0;
}