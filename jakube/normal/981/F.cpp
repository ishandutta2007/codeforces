#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, L;
    cin >> n >> L;
    vector<int> a(n), b(3*n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i+n] = b[i] - L;
        b[i+2*n] = b[i] + L;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int l = -1; // too small
    int r = L; // possible
    while (l + 1 < r) {
        int m = (l + r) / 2;
        int minShift = 0;
        int maxShift = 2*n;
        for (int i = 0; i < n; i++) {
            while (a[i] - b[i+minShift] > m)
                minShift++;
            while (b[i+maxShift] - a[i] > m)
                maxShift--;
        }
        if (minShift <= maxShift)
            r = m;
        else
            l = m;
    }
    cout << r << '\n';
}