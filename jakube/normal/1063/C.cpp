#include <bits/stdc++.h>
using namespace std;

bool guess(int x) {
    cout << x << " 1" << endl;
    string s;
    cin >> s;
    return s == "white";
}

int main() {
    int n;
    cin >> n;
    int L = -1;
    int R = 1'000'000'000;
    bool left_white = false;

    if (guess(0))
        left_white = true;
    L = 1;

    for (int i = 2; i <= n; i++) {
        int M = (L + R) / 2;
        if (guess(M)) { // white
            if (left_white)
                L = M;
            else
                R = M;
        } else { // black
            if (left_white)
                R = M;
            else
                L = M;
        }
    }
    cout << L << " " << 2 << " " << R << " " << 0 << endl;
}