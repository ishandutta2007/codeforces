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
#include<unordered_map>
#include<deque>
#include<cmath>
#include<iterator>





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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;

void unite(set<pii>& s, pii x) {
    if (x.first > x.second)
        return;
    auto it = s.upper_bound(x);
    if (it != s.begin()) {
        auto pr = prev(it);
        if (pr->second + 1 == x.first) {
            x.first = pr->first;
            s.erase(pr);
        }
    }
    it = s.upper_bound(x);
    if (it != s.end()) {
        if (it->first ==  x.second + 1) {
            x.second = it->second;
            s.erase(it);
        }
    }
    s.insert(x);
}

vector<string> solve(vector<string> input, vector<pair<int, string> > changes) {
    int n = input.size();
    vector<string> msg(n + 2);
    msg[0] = "blue";
    msg[n + 1] = "unlock";
    for (int i = 1; i <= n; ++i) {
        msg[i] = input[i - 1];
    }
    set<int> locks, unlocks;
    set<pii> segs;
    int lock = 0;
    int firstLock = n + 5;
    for (int i = 1; i <= n + 1; ++i) {
        if (msg[i] == "lock") {
            locks.insert(i);
            lock = 1;
            firstLock = min(firstLock, i);
        }
        if (msg[i] == "unlock") {
            unlocks.insert(i);
            if (lock) {
                lock = 0;
                unite(segs, pii(firstLock, i));
                firstLock = n + 5;
            }
            else {
                unite(segs, pii(i, i));
            }
        }
    }
    vector<string> res(changes.size() + 1);
    res[0] = msg[(segs.rbegin())->first - 1];
    
    locks.insert(-2);
    unlocks.insert(-1);
    segs.insert(pii(-2, -1));
    locks.insert(n + 2);
    unlocks.insert(n + 3);
    for (int i = 0; i < changes.size(); ++i) {
        int id = changes[i].first;
        string s = changes[i].second;
        if (msg[id] == "lock") {
            auto it = segs.lower_bound(pii(id, n + 5));
            auto pr = prev(it);
            pii sg = *pr;
            if ((id >= sg.first) && (id <= sg.second)) {
                auto id1 = locks.lower_bound(id);
                auto id2 = unlocks.lower_bound(id);
                if (*prev(id2) < *prev(id1)) {
                }
                else {
                    segs.erase(sg);
                    unite(segs, pii(sg.first, id - 1));
                    unite(segs, pii(min(*next(id1), *id2), sg.second));
                }
            }
            else {
                exit(0);
            }
            locks.erase(id);
        }

        if (msg[id] == "unlock") {
            auto it = segs.lower_bound(pii(id, n + 5));
            auto pr = prev(it);
            pii sg = *pr;
            if ((id >= sg.first) && (id <= sg.second)) {
                segs.erase(sg);
                auto id1 = locks.lower_bound(id);
                auto id2 = unlocks.lower_bound(id);
                bool fin = 0;
                if (id != sg.second) {
                    if (*prev(id2) > *prev(id1)) {
                        unite(segs, pii(sg.first, id - 1));
                        unite(segs, pii(id + 1, sg.second));
                    }
                    else {
                        unite(segs, sg);
                    }
                }
                else {
                    if (*prev(id2) > *prev(id1)) {
                        unite(segs, pii(sg.first, *prev(id2)));
                    }
                    else {
                        unite(segs, pii(sg.first, min(*next(id2), *id1) - 1));
                    }
                }
            }
            else {
                exit(0);
            }
            unlocks.erase(id);
        }

        msg[id] = s;

        if (s == "lock") {
            auto it = segs.lower_bound(pii(id, n + 5));
            auto pr = prev(it);
            pii sg = *pr;
            if ((id >= sg.first) && (id <= sg.second)) {
                
            } else {
                auto id1 = locks.lower_bound(id);
                auto id2 = unlocks.lower_bound(id);
                unite(segs, pii(id, min(*id2, *id1) - 1));
            }
            locks.insert(id);
        }

        if (s == "unlock") {
            auto it = segs.lower_bound(pii(id, n + 5));
            auto pr = prev(it);
            pii sg = *pr;

            if ((id >= sg.first) && (id <= sg.second)) {
                segs.erase(sg);
                unite(segs, pii(sg.first, id));
                auto id1 = locks.lower_bound(id);
                auto id2 = unlocks.lower_bound(id);
                if (*id1 < *id2) {
                    unite(segs, pii(*id1, sg.second));
                }
                else {
                    unite(segs, pii(*id2, sg.second));
                }

            } else {
                unite(segs, pii(id, id));
            }
            unlocks.insert(id);
        }
        res[i + 1] = msg[prev(segs.end())->first - 1];

    }
    return res;

}

vector<string> solveBrute(vector<string> input, vector<pair<int, string> > changes) {
    int n = input.size();
    vector<string> msg(n + 1);
    msg[0] = "blue";
    for (int i = 1; i <= n; ++i) {
        msg[i] = input[i - 1];
    }
    vector<string> res;
    for (int qq = 0; ; ++qq) {
        int lock = 0;
        string ans = "blue";
        for (int i = 1; i <= n; ++i) {
            if (msg[i] == "lock") {
                lock = 1;
            }
            else {
                if (msg[i] == "unlock") {
                    lock = 0;
                }
                else {
                    if (lock == 0)
                        ans = msg[i];
                }
            }
        }
        res.push_back(ans);
        if (qq == changes.size())
            break;
        msg[changes[qq].first] = changes[qq].second;
    }
    return res;
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
/*int c = 0;

while (true) {
    vector<string> s = {"lock", "unlock", "red", "blue"};
    int n = 10;
    int q = 10;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[rand() % 4];
    }

    vector<pair<int, string> > b(q);
    for (int i = 0; i < q; ++i) {
        b[i].first = rand() % n + 1;
        b[i].second = s[rand() % 4];
    }

    vector<string> res1 = solve(a, b);
    vector<string> res2 = solveBrute(a, b);

    if (res1 != res2) {
        cout << "!!!!!!!!!!!\n";
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i] << endl;
        }
        for (int i = 0; i < res1.size(); ++i) {
            cout << res1[i] << " " << res2[i] << endl;
        }
        break;
    }
    else {
        cout << ++c << " " << "OK\n";
    }

}*/
int n, q;
cin >> n;
vector<string> a(n);
for (int i = 0; i < n; ++i) {
    cin >> a[i];
}
cin >> q;
vector<pair<int, string> > b(q);
for (int i = 0; i < q; ++i) {
    cin >> b[i].first >> b[i].second;
}
vector<string> res = solve(a, b);
for (int i = 0;  i < res.size(); ++i) {
    cout << res[i] << endl;
}

//solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}