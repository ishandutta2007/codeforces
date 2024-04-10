#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(a);
        sort(b.begin(), b.end());
        map<int, int> toIndex;
        int currIndex = 0;
        int prevValue = -1;
        for (int i = 0; i < n; i++) {
            if (b[i] != prevValue) {
                toIndex[b[i]] = currIndex;
                prevValue = b[i];
                currIndex++;
            }
        }
        for (int i = 0; i < n; i++) {
            a[i] = toIndex[a[i]];
        }
        vector<vector<int>> sameValueIndices(n, vector<int>());
        for (int i = 0; i < n; i++) {
            sameValueIndices[a[i]].push_back(i);
        }

        vector<int> prev(n, -1);
        vector<int> nextSame(n, -1);
        vector<int> nextBigger(n, -1);
        vector<int> last(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < sameValueIndices[i].size(); j++) {
                prev[sameValueIndices[i][j]] = sameValueIndices[i][j - 1];
            }

            for (int j = 0; j + 1 < sameValueIndices[i].size(); j++) {
                nextSame[sameValueIndices[i][j]] = sameValueIndices[i][j + 1];
            }

            if (sameValueIndices[i].size() > 0) {
                int nextIndex = i + 1;
                while (nextIndex < n && sameValueIndices[nextIndex].size() == 0) {
                    nextIndex++;
                }
                if (nextIndex == n) {
                    continue;
                }
                int currIndex = 0;
                for (int j = 0;  j < sameValueIndices[i].size(); j++) {
                    while (currIndex < sameValueIndices[nextIndex].size() &&
                           sameValueIndices[nextIndex][currIndex] <
                           sameValueIndices[i][j]) {
                        currIndex++;
                    }
                    if (currIndex == sameValueIndices[nextIndex].size()) {
                        break;
                    }
                    nextBigger[sameValueIndices[i][j]] = sameValueIndices[nextIndex][currIndex];
                }
            }
        }

        vector<int> sameSubseqDP(n, -1);
        vector<int> subseqDP(n, -1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < sameValueIndices[i].size(); j++) {
                sameSubseqDP[sameValueIndices[i][j]] = sameValueIndices[i].size() - j;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            subseqDP[i] = sameSubseqDP[i];
            if (nextSame[i] != -1) {
                subseqDP[i] = max(subseqDP[i], subseqDP[nextSame[i]] + 1);
            }
            if (nextBigger[i] != -1) {
                subseqDP[i] = max(subseqDP[i], 1 + sameSubseqDP[nextBigger[i]]);
                if (prev[nextBigger[i]] == -1) {
                    int tempIndex = a[nextBigger[i]];
                    int tempSize = sameValueIndices[tempIndex].size();
                    subseqDP[i] = max(subseqDP[i], tempSize + subseqDP[sameValueIndices[tempIndex][tempSize - 1]]);
                }
            }
        }

        int maxSubseqDP = -1;
        for (int i = 0; i < n; i++) {
            maxSubseqDP = max(maxSubseqDP, subseqDP[i]);
        }
        cout << n - maxSubseqDP << "\n";
    }
}