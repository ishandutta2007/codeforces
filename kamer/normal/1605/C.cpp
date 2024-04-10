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
        vector<string> patterns;
        patterns.push_back("aa");
        patterns.push_back("aba");
        patterns.push_back("aca");
        patterns.push_back("abca");
        patterns.push_back("acba");
        patterns.push_back("abbacca");
        patterns.push_back("accabba");
        int shortest_length = -1;
        bool should_break = false;
        for (auto pattern : patterns) {
            int x = pattern.length();
            for (int i = 0; i < n - x + 1; i++) {
                bool match = true;
                for (int j = i; j < i + x; j++) {
                    if (s[j] != pattern[j - i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    shortest_length = x;
                    should_break = true;
                    break;
                }
            }

            if (should_break) {
                break;
            }
        }
        
        cout << shortest_length << "\n";
    }
}