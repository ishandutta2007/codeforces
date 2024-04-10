#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int moves = 1000;
        int brackets = 0;
        for (auto c : s) {
            if (c == ')') brackets--;
            if (c == '(') brackets++;
            moves = min(moves, brackets);
        }

        cout << -moves << "\n";
    }
}