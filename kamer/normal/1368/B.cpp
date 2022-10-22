#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

const int NUM_CHARS = 10;
typedef long long ll;

int main(void) {
    ll k;
    cin >> k;
    if (k == 1) {
        cout << "codeforces\n";
        return 0;
    }

    ll root = 0;
    while (true) {
        ll power = 1;
        for (int i = 0; i < NUM_CHARS; i++) {
            power *= root;
        }
        if (power < k) root++;
        else break;
    }
    root--;
    vector<int> numChars(NUM_CHARS, root);
    int currentIndex = 0;
    while (true) {
        numChars[currentIndex] = root + 1;
        currentIndex++;
        ll product = 1;
        for (auto el : numChars) product *= el;
        if (product >= k) break;
    }
    string s = "codeforces";
    for (int i = 0; i < NUM_CHARS; i++) {
        for (int j = 0; j < numChars[i]; j++) {
            cout << s[i];
        }
    }
    cout << "\n";
}