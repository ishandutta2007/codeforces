#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& a) {
    for (int d = a.size(); d--;) {
        int m = 0;
        for (int i = 0; i < d; i++) {
            if (abs(a[i] - a[i + 1]) >= 2) return false;
        }
        for (int i = 0; i <= d; i++) {
            if (a[m] < a[i]) m = i;
        }
        for (; m < d; m++) swap(a[m], a[m + 1]);
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    puts(solve(a) ? "YES" : "NO");
}