#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];
        vector<int> charCounts(30, 0);
        for (auto c : s) {
            charCounts[c - 'a']++;
        }
        vector<char> t(m);
        char currChar = 'z';
        for (int i = 0; i < 30; i++) {
            vector<int> zeroIndices;
            for (int j = 0; j < m; j++) {
                if (b[j] == 0) zeroIndices.push_back(j);
            }
            if (zeroIndices.size() == 0) {
                break;
            }
            while (charCounts[currChar - 'a'] < zeroIndices.size()) {
                currChar--;
            }
            for (auto index : zeroIndices) t[index] = currChar;
            currChar--;
            for (auto index : zeroIndices) b[index] = -1;
            for (int i = 0; i < m; i++) {
                for (auto index : zeroIndices) {
                    b[i] -= abs(i - index);
                }
            }
        }
        
        for (auto c : t) cout << c;
        cout << "\n";
    }
}