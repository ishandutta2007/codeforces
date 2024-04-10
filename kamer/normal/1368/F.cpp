#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <cmath>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    if (n < 4) {
        cout << "0\n";
        cout.flush();
        return 0;
    }

    vector<bool> good(n, false);
    unordered_set<int> remainingNumbers;
    unordered_set<int> badNumbers;
    int k = int(floor(sqrt(n - 1)));
    if (n - 1 >= k * (k + 1)) k++;
    int s = 0;
    for (; s < n - k; s += k) {
        badNumbers.insert(s + k);
        for (int i = 0; i < k - 1; i++) {
            remainingNumbers.insert(s + i + 1);
        }
    }
    for (int i = s; i < n - 1; i++) {
        if (i == s) {
            badNumbers.insert(n);
        }
        remainingNumbers.insert(i + 1);
    }

    while (remainingNumbers.size() > k - 1) {
        unordered_set<int> query;
        for (auto number : remainingNumbers) {
            query.insert(number);
            if (query.size() == k) {
                break;
            }
        }
        for (auto queryNumber : query) {
            remainingNumbers.erase(queryNumber);
        }
        cout << k;
        for (auto queryNumber : query) {
            cout << " " << queryNumber;
        }
        cout << "\n";
        cout.flush();
        
        int x;
        cin >> x;
        if (x == -1) {
            return 0;
        }
        for (int i = x; i < x + k; i++) {
            if (badNumbers.find((i - 1) % n + 1) == badNumbers.end()) {
                remainingNumbers.insert((i - 1) % n + 1);
            }
        }
    }

    cout << "0\n";
    cout.flush();
    return 0;
}