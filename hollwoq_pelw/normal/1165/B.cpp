#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++) cin >> a[i];
    sort(a, a+n);
    int d = 0;
    for (int i = 0; i < n; i++){
        if (a[i] >= d+1) d++;
    }
    cout << d;
    return 0;
}