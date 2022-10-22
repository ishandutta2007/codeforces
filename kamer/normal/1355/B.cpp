#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int T = 0; T < t; T++) {
        int n;
        cin >> n;
        vector<int> e(n);
        for (int i = 0; i < n; i++) {
            cin >> e[i];
        }
        sort(e.begin(), e.end());
        int numGroups = 0;
        int currSize = 0;
        int currBiggest = 0;
        bool constructing = false;
        for (int i = 0; i < n; i++) {
            if (!constructing) {
                constructing = true;
                currBiggest = e[i];
                currSize = 1;
            } else {
                currSize += 1;
                currBiggest = e[i];
            }

            if (currSize >= currBiggest) {
                constructing = false;
                numGroups += 1;
            }
        }
        cout << numGroups << "\n";
    }
    
    return 0;
}