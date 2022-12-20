#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int sm = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sm += x;
        }
        int out = sm/n;
        if (sm % n) out++;
        cout << out << endl;
    }
}