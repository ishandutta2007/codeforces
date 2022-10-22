#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> countZero(n + 1);
        vector<int> countOne(n + 1);
        int totalCountZero = 0, totalCountOne = 0;
        countZero[0] = 0;
        countOne[0] = 0;
        for (int i = 0; i < n; i++) {
            countZero[i + 1] = countZero[i];
            countOne[i + 1] = countOne[i];
            if (s[i] == '0') {
                totalCountZero++;
                countZero[i + 1]++;
            } else if (s[i] == '1') {
                totalCountOne++;
                countOne[i + 1]++;
            }
        }
        int bestMoves = min(totalCountOne, totalCountZero);
        for (int i = 0; i < n; i++) {
            bestMoves = min(bestMoves, countOne[i + 1] + n - countZero[i + 1] - totalCountOne);
            bestMoves = min(bestMoves, countZero[i + 1] + n - countOne[i + 1] - totalCountZero);
        }
        cout << bestMoves << "\n";
    }
}