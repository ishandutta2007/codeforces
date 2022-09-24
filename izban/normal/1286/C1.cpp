#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

#undef LOCAL

mt19937 rnd;

int asked;
int answered;

int n;
string s;
int readN() {
    asked = answered = 0;
#ifdef LOCAL
    n = rnd() % 10 + 1;
    s = "";
    for (int i = 0; i < n; i++) s += (char)('a' + rnd() % n);
    return n;
#else
    cin >> n;
    return n;
#endif
}

vector<string> get(int l, int r) {
    vector<string> res;
    int cnt = (r - l + 1) * (r - l + 2) / 2;
    asked += 1;
    answered += cnt;
#ifdef LOCAL
    for (int i = l; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            string t = s.substr(i, j - i + 1);
            random_shuffle(t.begin(), t.end());
            res.push_back(t);
        }
    }
    assert(res.size() == cnt);
    random_shuffle(res.begin(), res.end());
#else
    cout << "? " << l+1 << " " << r+1 << endl;
    for (int i = 0; i < cnt; i++) {
        string t;
        cin >> t;
        res.push_back(t);
    }
#endif
    return res;
}

bool cmp (const string &s1, const string &s2) {
    if (s1.length() != s2.length()) return s1.length() > s2.length();
    return s1 < s2;
}

vector<string> ask(int l, int r) {
    if (l > r) return vector<string>();
    auto ans = get(l, r);
    for (auto &s : ans) {
        sort(s.begin(), s.end());
    }
    sort(ans.begin(), ans.end(), cmp);
    return ans;
}

void ans(string ans) {
    assert(asked <= 3);
    assert(answered <= (n + 1) * (n + 1));
#ifdef LOCAL
    assert(ans == s);
#else
    cout << "! " << ans << endl;
#endif
}

void solve() {
    int n = readN();

    auto res1 = ask(0, n - 1);
    auto res2 = ask(1, n - 1);

    auto dif = [&](const string &s1, const string &s2) {
        vector<int> cnt(26);
        for (char c : s1) cnt[c - 'a']++;
        for (char c : s2) cnt[c - 'a']--;
        int res = 0;
        while (cnt[res] == 0) res++;
        assert(res < 26 && cnt[res] == 1);
        return (char)('a' + res);
    };

    map<string, int> mp;
    vector<string> vct;
    for (auto s : res1) mp[s]++;
    for (auto s : res2) mp[s]--;
    for (auto it : mp) {
        if (it.second > 0) {
            vct.push_back(it.first);
        }
    }
    sort(vct.begin(), vct.end(), cmp);
    reverse(vct.begin(), vct.end());
    assert(vct.size() == n);
    assert(vct[0].length() == 1);
    for (int i = 1; i < (int)vct.size(); i++) assert(vct[i].length() == vct[i - 1].length() + 1);

    string s(n, '-');
    s[0] = vct[0][0];
    for (int i = 1; i < n; i++) s[i] = dif(vct[i], vct[i - 1]);
    ans(s);
}

int main() {
#ifdef LOCAL
    for (int it = 0;; it++) {
        rnd = mt19937(it);
        db(it);
        solve();
    }
#endif

    solve();

    return 0;
}