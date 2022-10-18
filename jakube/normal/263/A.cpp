#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    for (int i = 0; i < 5; ++i) {
        vector<int> v(5);
        for (int idx = 0; idx < 5;  idx++) {
            cin >> v[idx];
            if (v[idx]) {
                cout << abs(2 - idx) + abs(2 - i) << endl;
            }
        }
        
    }
    

    return 0;
}