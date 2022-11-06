#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> iipair;
typedef pair <ll,ll> llpair;

const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const double EPS = 1e-8;

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
const double PI = acos(-1.0);

const ll MOD = 1000000007;
int main() {
    ios::sync_with_stdio(false);
    int n;
    string s, t;
    cin >> n >> s >> t;
    if (s == t) cout << 26 * (n + 1);
    else {
        int rez = 0;
        int i = 0;
        int j = 0;
        while (i < n && s[i] == t[j]){
            ++i;
            ++j;
        };
        ++i;
        while (i < n && s[i] == t[j]){
            ++i;
            ++j;
        };
        ++j;
        while (i < n && s[i] == t[j]){
            ++i;
            ++j;
        };
        if (i == n) ++rez;
        i = 0;
        j = 0;
        while (i < n && s[i] == t[j]){
            ++i;
            ++j;
        };
        ++j;
        while (i < n && s[i] == t[j]){
            ++i;
            ++j;
        };
        ++i;
        while (i < n && s[i] == t[j]){
            ++i;
            ++j;
        };
        if (i == n) ++rez;
        cout << rez;
    };
    return 0;
};