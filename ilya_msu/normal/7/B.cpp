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
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1000000;



void solve() {
    int t, m;
    cin >> t >> m;
    vector<int> start(1, -1);
    vector<int> len(1, -1);
    vector<int> used(m, 0);
    for (int tt = 0; tt < t; ++tt) {
        string s;
        cin >> s;
        if (s == "alloc") {
            int n;
            cin >> n;
            int free = 0;
            for (int i = 0; i < m; ++i) {
                if (used[i])
                    free = 0;
                else
                    ++free;
                if (free == n) {
                    for (int j = i - n + 1; j <= i; ++j)
                        used[j] = start.size();
                    cout << start.size() << endl;
                    start.push_back(i - n + 1);
                    len.push_back(n);
                    break;
                }
            }
            if (free != n) {
                cout << "NULL" << endl;
            }
            continue;
        }
        if (s == "erase") {
            int x;
            cin >> x;
            bool ok = 0;
            if ((x >= 0) && (x < start.size()) && (start[x] != -1)) {
                ok = 1;
                for (int i = start[x]; i < start[x] + len[x]; ++i)
                    used[i] = 0;
                start[x] = -1;
            }
            if (!ok) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
            continue;
        }
        int st = -1;
        for (int i = 0; i < m; ++i) {
            if (used[i] == 0) {
                if (st == -1)
                    st = i;
            }
            else {
                if (st != -1) {
                    start[used[i]] = st;
                    int x = used[i];
                    for (int j = st; j < st + len[x]; ++j) {
                        used[j] = x;
                    }
                    for (int j = max(i, st + len[x]); j < i + len[x]; ++j) {
                        used[j] = 0;
                    }
                    if (st + len[x] <= i)
                        st = st + len[x];
                    else
                        st = -1;
                    i = max(i, st + len[x] - 1);
                }
            }
        }
    }    
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