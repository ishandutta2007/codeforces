#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define int long long

int cnt[26];

void solve() {
    for (int i = 0; i < 26; i++) {
        cnt[i] = 0;
    }
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
    {
        int diff = 0;
        for (int i = 0; i < 26; i++) {
            diff += cnt[i] > 0;
        }
        if (diff == 1) {
            cout << s << endl;
            return;
        }
    }
    int cnt1 = -1;
    int cnt2 = -1;
    int ind1 = -1;
    int ind2 = -1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            if (cnt1 == -1) {
                cnt1 = cnt[i];
                ind1 = i;
                continue;
            }
            if (cnt2 == -1) {
                cnt2 = cnt[i];
                ind2 = i;
                continue;
            }
        }
    }

    for (int _ = 0; _ < 26; _++) {
        if (cnt[_] == 1) {
            cout << (char)('a' + _);
            cnt[_]--;
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < cnt[i]; j++) {
                    cout << (char)('a' + i);
                }
            }
            cout << endl;
            return;
        }
    }
    if (cnt1 * 2 <= n + 2) {
        cout << (char)('a' + ind1) << (char)('a' + ind1);
        cnt[ind1] -= 2;
        for (int i = 2; i < n; i++) {
            if (cnt[ind1] == 0) {
                break;
            }
            if (i % 2 == 0) {
                for (int j = ind1 + 1; j < 26; j++) {
                    if (cnt[j] > 0) {
                        cout << (char)('a' + j);
                        cnt[j]--;
                        break;
                    }
                }
            } else {
                cout << (char)('a' + ind1);
                cnt[ind1]--;
            }
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << (char)('a' + i);
            }
        }
        cout << endl;
    } else {
        cout << (char)('a' + ind1) << (char)('a' + ind2);
        cnt[ind1]--;
        cnt[ind2]--;
        int keke = -1;
        for (int i = ind2 + 1; i < 26; i++) {
            if (cnt[i] > 0) {
                keke = i;
                break;
            }
        }

        if (keke != -1) {
            for (int i = 0; i < cnt[ind1]; i++) {
                cout << (char)('a' + ind1);
            }
            cnt[ind1] = 0;
            cout << (char)('a' + keke);
            cnt[keke]--;
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < cnt[i]; j++) {
                    cout << (char)('a' + i);
                }
            }
            cout << endl;
            return;
        } else {
            for (int i = 0; i < cnt[ind2]; i++) {
                cout << (char)('a' + ind2);
            }
            for (int i = 0; i < cnt[ind1]; i++) {
                cout << (char)('a' + ind1);
            }
            cout << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}