#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(void) {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll maxim = -1;

    if (n == 1) cout << a[0];
    else if (n == 2) cout << (a[0] | a[1]);
    else {


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((a[i] | a[j] | a[k]) > maxim) maxim = (a[i] | a[j] | a[k]);
            }
        }
    }
    cout << maxim;
    }
}