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

vector<int> div(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.pb(i);
            if (i * i != n) {
                res.pb(n / i);
            }
        }
    }
    return res;
}

bool check(int n, int m, int k) {
    vector<int> a = {n, m, n, m - 1};
    for (int i = 0; i < 3; ++i) {
        if (a[i] % k == 0) {
            a[i + 1]--;
        } else if (a[i] % k == 1) {
            continue;
        } else {
            return false;
        }
    }
    if (a[3] % k != 0) return false;
    return true;
}

vector<int> solve(int n, int m) {
    vector<int> res;
    for (auto c : div(n)) if (check(n, m, c)) res.pb(c);
    for (auto c : div(n - 1)) if (check(n, m, c)) res.pb(c);
    return res;
}


void solve() {
    int n, m; cin >> n >> m;
    set<int> s;
    for (auto c : solve(n, m)) s.insert(c);
    for (auto c : solve(m, n)) s.insert(c);
    cout << s.size() << ' ';
    for (auto c : s) cout << c << ' ';
    cout << '\n';
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