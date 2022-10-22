#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        int lastElem = -1;
        bool isSorted = true;;
        int countZero = 0, countOne = 0;
        for (int i = 0; i < n; i++) { cin >> a[i];
            if (a[i] < lastElem) isSorted = false;
            lastElem = a[i];
        }
        for (int i = 0; i < n; i++) { cin >> b[i];
            if (b[i] == 0) countZero++;
            else           countOne++;
        }
        if (countZero != 0 && countOne != 0) {
            cout << "Yes\n";
        } else {
            if (isSorted) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}