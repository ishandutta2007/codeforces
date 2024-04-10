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

//vector<int> solve(int n, int m) {
//
//}

void reduce(string& s) {
    string t;
    int b_cnt = 0;
    for (auto c : s) {
        if (c == 'B') ++b_cnt;
        else if (c == 'A') {
            if (!t.empty() && t.back() == 'A') t.pop_back();
            else t.push_back('A');
        } else if (c == 'C') {
            if (!t.empty() && t.back() == 'C') t.pop_back();
            else t.push_back('C');
        }
    }
    if (b_cnt % 2 == 1) {
        t += 'B';
    }
    s = t;
}


void solve() {
//    int n, m; cin >> n >> m;
//    set<int> s;
//    for (auto c : solve(n, m)) s.insert(c);
//    for (auto c : solve(m, n)) s.insert(c);
//    cout << s.size() << ' ';
//    for (auto c : s) cout << c << ' ';

    string s,t; cin >> s >> t;
    reduce(s);
    reduce(t);
    if (s == t) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

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