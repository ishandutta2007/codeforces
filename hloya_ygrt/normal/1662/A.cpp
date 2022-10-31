#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back


typedef long long ll;
typedef long double ld;


const ll inf = 1e18 + 500;
const ll mod = 998244353;
//const ll mod = 1e9 + 7;
const ld eps= 1e-9;

void solve() {
    int n; cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        m[y] = max(m[y], x);
    }
    int s = 0;
    for (int i = 1; i <= 10; ++i) {
        if (!m.count(i)) {
            cout << "MOREPROBLEMS\n";
            return;
        }
        s += m[i];
    }
    cout << s << '\n';
}


int main() {
//                freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //    std::random_device rd;
    //    std::mt19937 g(rd());
    auto start = clock();

    ll t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    std::cerr << ld(clock() - start) / CLOCKS_PER_SEC << std::endl;
    return 0;
}