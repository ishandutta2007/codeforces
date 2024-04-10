#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> cnt(29, 0);
        for (auto c : s) {
            cnt[c - 'a' + 1]++;
        }
        for (int i = 1; i < 27; i++) {
            cnt[i] += cnt[i - 1];
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            if ((i < cnt[s[i] - 'a']) || (i >= cnt[s[i] -'a' + 1])) k++;
        }
        cout << k << "\n";
    }
}