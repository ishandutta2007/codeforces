#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> div;
        for (int i = 2; i <= sqrt(n) + 2; i++) {
            if (n % i == 0) {
                n /= i;
                div.push_back(i);
            }
            if (div.size() >= 2 && n != 1) break;
        }
        //cout << div.size() << ' ' << n << endl;
        if (div.size() < 2 || (div.size() < 3 && n == 1)) {
            cout << "NO" << endl;
        } else if (n == div[0] || n == div[1]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << div[0] << ' ' << div[1] << ' ';
            if (n == 1) {
                cout << div[2] << endl;
            } else {
                cout << n << endl;
            }
        }
    }
}