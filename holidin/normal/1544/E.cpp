#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <random>
#include <bitset>
#include <map>
#include <unordered_map>
#include <queue>
#include <time.h>
#define fi first
#define se second
#define ll long long
#define int long long
#define ld double
#define mp make_pair
using namespace std;
const int inf = 1e15;
const int N = 1e6 + 13;
mt19937 rnd;
int cnt[N];


bool can_one(string s) {
    for (int i = 0; i < 26; ++i)
        if (cnt[i] == 1) {
            cout << (char) (i + 'a');
            --cnt[i];
            for (int j = 0; j < 26; ++j) {
                while (cnt[j] > 0) {
                    --cnt[j];
                    cout << (char) (j + 'a');
                }
            }
            cout << "\n";
            return true;
        }
    return false;
}
void solve(int num) {
    int n;
    string s;
    cin >> s;
    set<int> t;
    for (int i = 0; i < 26; ++i)
        cnt[i] = 0;
    for (auto c : s) {
        ++cnt[c - 'a'];
        t.insert(c);
    }
    if (can_one(s)) {
        return;
    }
    if (t.size() == 1) {
        cout << s << "\n";
        return;
    }
    int fs = 0;
    while (cnt[fs] == 0) {
        ++fs;
    }
    int sc = fs + 1;
    while (cnt[sc] == 0) {
        ++sc;
    }
    int left = s.size() - cnt[fs];
    if (left >= cnt[fs] - 2) {
        cout << (char) (fs + 'a') << (char) (fs + 'a') ;
        --cnt[fs];
        --cnt[fs];
        int sc = fs + 1;
        while (cnt[fs] > 0) {
            while (cnt[sc] == 0) {
                ++sc;
            }
            cout << (char) (sc + 'a');
            --cnt[sc];
            cout << (char) (fs + 'a');
            --cnt[fs];
        }
        for (int j = 0; j < 26; ++j) {
            while (cnt[j] > 0) {
                --cnt[j];
                cout << (char) (j + 'a');
            }
        }
        cout << "\n";
        return;
    }
    if (cnt[sc] == 1 || cnt[fs] == 1) {
        sort(s.begin(), s.end());
        cout << s << "\n";
        return;
    }
    int th = sc + 1;
    while (th < 26 && cnt[th] == 0) {
        ++th;
    }
    if (th == 26) {
        cout << (char) (fs + 'a');
        for (int i = 0; i < cnt[sc]; ++i)
            cout << (char) (sc + 'a');
        for (int i = 1; i < cnt[fs]; ++i)
            cout << (char) (fs + 'a');
        cout << "\n";
        return;
    }
    cout << (char) (fs + 'a');
    cout << (char) (sc + 'a');
    --cnt[fs];
    --cnt[sc];
    while (cnt[fs] > 0) {
        cout << (char) (fs + 'a');
        --cnt[fs];
    }
    cout << (char) (th + 'a');
    --cnt[th];
    for (int j = 0; j < 26; ++j) {
        while (cnt[j] > 0) {
            --cnt[j];
            cout << (char) (j + 'a');
        }
    }
    cout << "\n";
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // local
    int test = 1;
    cin >> test;
    int cnt = 0;
    while (test--) {
        ++cnt;
        solve(cnt);
    }

}