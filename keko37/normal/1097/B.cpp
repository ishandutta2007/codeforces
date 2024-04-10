#include<bits/stdc++.h>

using namespace std;

const int MAXN = 20;

int n;
int a[MAXN];

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<(1<<n); i++) {
        int sum = 0;
        for (int j=0; j<n; j++) {
            if (i & (1 << j)) sum += a[j]; else sum -= a[j];
        }
        if (sum % 360 == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}