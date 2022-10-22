#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int countR = 0, countS = 0, countP = 0;
        for (auto c : s) {
            if (c == 'R') countR++;
            if (c == 'S') countS++;
            if (c == 'P') countP++;
        }

        char c = 'R';
        if (countR >= countS && countR >= countP) c = 'P';
        if (countP >= countS && countP >= countR) c = 'S';
        for (int i = 0; i < s.length(); i++) cout << c;
        cout << "\n";
    }
}