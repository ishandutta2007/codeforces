#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int y;
    cin >> y;
    
    while (1) {
        y++;
        set<int> s;
        int x = y;
        int c = 0;
        while (x) {
            s.insert(x%10);
            x /= 10;
            c++;
        }
        if (s.size() == c) {
            cout << y << endl;
            return 0;
        }
    }

    return 0;
}