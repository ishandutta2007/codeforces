#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // we can check if the array is a bad boy
    // if there's an odd thing, we can just get rid of that

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    bool reach[300000];
    reach[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 3000000; j >= 0; j--) {
            if (j + a[i] >= 300000) continue;
            if (reach[j]) reach[j+a[i]] = true;
        }
    }

    int sm = 0;
    for (int i = 0; i < n; i++) sm += a[i];

    if (sm % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    if (!reach[sm/2]) {
        cout << 0 << endl;
        return 0;
    }

    int pow = 1;
    while (true) {
        for (int i = 0; i < n; i++) {
            if ((a[i]/pow) % 2 != 0) {
                cout << 1 << endl;
                cout << i+1 << endl;
                return 0;
            }
        }
        pow *= 2;
    }

    
}