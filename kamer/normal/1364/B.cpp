#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        vector<int> indices;
        indices.push_back(0);
        int currIndex = 1;
        bool direction = (p[1] > p[0]);
        while (currIndex < n) {
            if (currIndex == n -1) { indices.push_back(currIndex);
                currIndex++;
            } else {
                if (direction == (p[currIndex + 1] > p[currIndex])) {
                    currIndex++;
                } else {
                    indices.push_back(currIndex);
                    direction = !direction;
                    currIndex++;
                }
            }
        }
        cout << indices.size() << "\n";
        for (auto el : indices) cout << p[el] << " " ;
        cout << "\n";
    }
}