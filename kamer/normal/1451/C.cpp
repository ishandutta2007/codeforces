#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        vector<int> a_counts(26, 0);
        vector<int> b_counts(26, 0);
        for (auto c : a) a_counts[c - 'a']++;
        for (auto c : b) b_counts[c - 'a']++;
        bool mod_cond = true;
        for (int i = 0; i < 26; i++) {
            if (a_counts[i] % k != b_counts[i] % k) {
                mod_cond = false;
                break;
            }
        }

        int a_pref = 0;
        int b_pref = 0;
        bool pref_cond = true;
        for (int i = 0; i < 26; i++) {
            a_pref += a_counts[i];
            b_pref += b_counts[i];
            if (a_pref < b_pref) {
                pref_cond = false;
                break;
            }
        }

        if (mod_cond && pref_cond) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

    }
}