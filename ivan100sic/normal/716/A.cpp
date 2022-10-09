#include <bits/stdc++.h>
using namespace std;

int main() {
        int n, c, s=0, last=-1;
        cin >> n >> c;
        for (int i=0; i<n; i++) {
                int x;
                cin >> x;
                if (i == 0 || x - last <= c) {
                        s++;
                } else {
                        s = 1;
                }
                last = x;
        }
        cout << s << '\n';
}