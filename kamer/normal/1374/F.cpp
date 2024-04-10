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
        vector<int> a(n);
        vector<int> ops;
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < n - 2; i++) {
            int minIndex = -1;
            int minim = 1000;
            for (int j = i; j < n; j++) {
                if (minim > a[j]) {
                    minIndex = j;
                    minim = a[j];
                }
            }

            while (minIndex >= i + 2) {
                ops.push_back(minIndex - 2);
                int temp = a[minIndex];
                a[minIndex] = a[minIndex - 1];
                a[minIndex - 1] = a[minIndex - 2];
                a[minIndex - 2] = temp;
                minIndex -= 2;
            }

            if (minIndex == i + 1) {
                ops.push_back(i);
                ops.push_back(i);
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = a[i + 2];
                a[i + 2] = temp;
            }
        }

        if (a[n - 2] > a[n - 1]) {
            // try to find to equal
            if (n >= 3 && a[n - 3] == a[n - 1]) {
                ops.push_back(n - 3);
            } else {
                int prevValue = -1;
                int goodIndex = -1;
                for (int i = 0; i < n - 2; i++) {
                    if (a[i] == prevValue) {
                        goodIndex = i - 1;
                        break;
                    }
                    prevValue = a[i];
                }
                if (goodIndex == -1) {
                    cout << "-1\n";
                    continue;
                }
                for (int i = goodIndex; i < n - 2; i++) {
                    ops.push_back(i);
                    ops.push_back(i);
                }
            }
        }

        cout << ops.size() << "\n";
        for (auto op : ops) cout << op + 1 << " ";
        cout << "\n";
    }
}