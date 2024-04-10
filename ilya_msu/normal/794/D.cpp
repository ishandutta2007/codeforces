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
//#include<unordered_map>




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
const ll N = 1000000 * 2 + 100;





void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<vector<int>, int> > g(n);
    for (int i = 0; i < n; ++i) {
        g[i].first.push_back(i);
        g[i].second = i;
    }
    vector<pii> ed;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        ed.push_back(pii(a, b));
        g[a].first.push_back(b);
        g[b].first.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].first.begin(), g[i].first.end());
    }
    sort(g.begin(), g.end());
    vector<int> col(n);
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if ((i == 0) || (g[i].first == g[i - 1].first)) {
            col[g[i].second] = c;
        }
        else {
            ++c;
            col[g[i].second] = c;
        }
    }
    if (c == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    vector<vector<int> > degs(c + 1);
    for (int i = 0; i < ed.size(); ++i) {
        int c1 = col[ed[i].first], c2 = col[ed[i].second];
        if (c1 != c2) {
            degs[c1].push_back(c2);
            degs[c2].push_back(c1);

        }
    }
    
    bool ok = 1;
    int start = -1;
    for (int i = 0; i < degs.size(); ++i) {
        sort(degs[i].begin(), degs[i].end());
        degs[i].resize(unique(degs[i].begin(), degs[i].end()) - degs[i].begin());
        if (degs[i].size() == 1)
            start = i;
        if (degs[i].size() > 2)
            ok = 0;
    }
    if ((!ok) || (start == -1)) {
        cout << "NO\n";
        return;
    }
    vector<int> num(c + 1);
    num[start] = 0;
    int pr = -1;
    while (true) {
        int nxt = -1;
        for (int i = 0; i < degs[start].size(); ++i) {
            if (degs[start][i] != pr)
                nxt = degs[start][i];
        }
        if (nxt == -1)
            break;
        num[nxt] = num[start] + 1;
        pr = start;
        start = nxt;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << num[col[i]] + 1 << " ";
    }
    cout << endl;  
    
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