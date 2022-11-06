#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    int p = -1;
    for (auto i: primes) {
        cout << i << endl;
        string s;
        cin >> s;
        if (s == "yes") {
            if (p != -1) {
                cout << "composite" << endl;
                return 0;
            }
            p = i;
        }
    }

    if (p == -1 || p * p > 100) {
        cout << "prime" << endl;
    } else {
        cout << p * p << endl;
        string s;
        cin >> s;
        if (s == "no") cout << "prime" << endl;
        else cout << "composite" << endl;
    }
}