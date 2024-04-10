#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0 ; i < n; i++) cin >> b[i];

    int suma = 0;
    int sumb = 0;
    int diff = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            suma++;
        }
        if (b[i] == 1) {
            sumb++;
        }
        if (a[i] == 1 && b[i] == 0) {
            diff++;
        }
    }

    if (suma > sumb) {
        cout << 1 << endl;
    } else {
        if (diff == 0) {
            cout << -1 << endl;
        } else {
            cout << ceil((sumb-suma+1)/double(diff))+1 << endl;
        }
    }
}