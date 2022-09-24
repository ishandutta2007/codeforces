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



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    string s;
    while (cin >> n >> s) {
        vector<int> cnt(256);
        for (char c : s) cnt[c]++;

        int cnt_0 = cnt['z'];
        int cnt_1 = cnt['n'];

        cnt['z'] -= cnt_0;
        cnt['e'] -= cnt_0;
        cnt['r'] -= cnt_0;
        cnt['o'] -= cnt_0;

        cnt['o'] -= cnt_1;
        cnt['n'] -= cnt_1;
        cnt['e'] -= cnt_1;

        for (int x : cnt) assert(x == 0);

        vector<int> res;
        for (int i = 0; i< cnt_1; i++) res.push_back(1);
        for (int i = 0; i< cnt_0; i++) res.push_back(0);

        for (int i = 0; i < (int)res.size(); i++) printf("%d%c", res[i], " \n"[i + 1 == (int)res.size()]);
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}