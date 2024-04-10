#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    bool ones = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 1) ones = false;
    }
    sort(a, a+n);

    if (!ones) {
    cout << 1 << ' ';
    for (int i = 0 ;i < n-1; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    }

    else {
        for (int i = 0; i < n-1; i++) cout << 1 << ' ';
        cout << 2 << endl;
    }
}