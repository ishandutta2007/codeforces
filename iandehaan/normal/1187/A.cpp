#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int n, s, t;
        cin >> n >> s >> t;
        cout << n - min(s, t) + 1 << endl;
    }
}