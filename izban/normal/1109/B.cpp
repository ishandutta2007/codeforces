#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

string solve(string s) {
    int n = s.length();
    vector<int> cnt(26);
    for (char c : s) cnt[c - 'a']++;

    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());
    if (cnt[1] <= 1 && cnt[2] == 0) {
        return "Impossible";
    }

    for (int i = 0; i < n; i++) {
        string t = s.substr(i + 1) + s.substr(0, i + 1);
        string rt = t;
        reverse(rt.begin(), rt.end());
        if (t == rt && t != s) {
            return "1";
        }
    }
    return "2";
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    string s;
    while (cin >> s) {
        cout << solve(s) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}