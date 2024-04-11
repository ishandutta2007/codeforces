#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
int a[200050];
string ans;
void f(int lnext, int rnext, int nowval, string &ret) {
    if(lnext > rnext) return;
    if(max(a[lnext], a[rnext]) <= nowval) return;
    //cerr << nowval << endl;
    if(a[lnext] <= nowval) {
        ret += "R";
        f(lnext, rnext-1, a[rnext], ret);
        return;
    }
    if(a[rnext] <= nowval) {
        ret += "L";
        f(lnext+1, rnext, a[lnext], ret);
        return;
    }
    if(a[rnext] < a[lnext]) {
        ret += "R";
        f(lnext, rnext-1, a[rnext], ret);
        return;
    }
    if(a[rnext] > a[lnext]) {
        ret += "L";
        f(lnext+1, rnext, a[lnext], ret);
        return;
    }
    string ret1 = ret + "L";
    string ret2 = ret + "R";
    f(lnext+1, rnext, a[lnext], ret1);
    f(lnext, rnext-1, a[lnext], ret2);
    if(ret1.size() > ret2.size()) ret = ret1;
    else ret = ret2;
    return;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    string ans;
    f(1, n, 0, ans);
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}