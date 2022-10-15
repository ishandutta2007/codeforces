#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

string gl = "aoeiu";

bool isSog(char c) {
    for (int i = 0; i < 5; ++i)
        if (c == gl[i])
            return 0;
    return 1;
}


void solve() {
    string s;
    cin >> s;
    string res = "";
    int count = 0;
    int eq = 1;
    char lst = ' ';
    for (int i = 0; i < s.size(); ++i) {
        if (isSog(s[i])) {
            ++count;
            if (count > 1) {
                if (lst != s[i])
                    eq = 0;
            }
            lst = s[i];
        }
        else {
            count = 0;
            lst = ' ';
            eq = 1;
        }
        if ((count > 2) && (eq == 0)) {
            res += ' ';
            count = isSog(s[i]);
            eq = 1;
            lst = s[i];
        }
        res += s[i];
    }
    cout << res << endl;
}



//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}