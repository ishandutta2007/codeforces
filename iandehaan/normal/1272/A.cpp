#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int cs = 0; cs < q; cs++) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);

        if (a[0] == a[1]) {
            if (a[1] != a[2]) {
                a[0]++;
                a[1]++;
                if (a[1] != a[2]) {
                    a[2]--;
                }
            }
        } else if (a[1] == a[2]) {
            if (a[1] != a[0]) {
                a[1]--;
                a[2]--;
                if (a[1] != a[0]) {
                    a[0]++;
                }
            }
        } else {
            a[0]++;
            a[2]--;
        }

        cout << abs(a[1]-a[0]) + abs(a[2]-a[0]) + abs(a[2]-a[1]) << endl;
    }
}