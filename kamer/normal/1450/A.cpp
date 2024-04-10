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
        string s;
        cin >> n >> s;
        vector<int> cnts(26, 0);
        for (auto c : s) cnts[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnts[i]; j++) {
                char c = 'a' + i;
                cout << c;
            }
        }
        cout << "\n";
    }
}