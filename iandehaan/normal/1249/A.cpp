#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int cs = 0; cs < q; cs++) {
        int n;
        cin >> n;
        int a[n];
        bool need2 = false;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (abs(a[i]-a[j]) == 1) {
                    need2 = true;
                    break;
                }
            }
        }

        if (need2) cout << 2 << endl;
        else cout << 1 << endl;
    }
}