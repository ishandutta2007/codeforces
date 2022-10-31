#include <bits/stdc++.h>

using namespace std;

int a[1001], b[1001];
int n;
double m;
    
const double eps = 1e-12;

bool can(double have) {
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double weight = have + m;
        double need = weight / (double)a[i];
        if (need > have - eps) {
            return false;
        }
        have -= need;
        weight = have + m;
        need = weight / (double)b[j];
        if (need > have - eps) {
            return false;
        }
        have -= need;
    }
    return true;
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    double l = 0, r = 2e9;
    for (int it = 0; it < 1000; it++) {
        double mid = (l + r) / 2.;
        if (can(mid))
            r = mid;
        else
            l = mid;
    }
    if (l > (double)1e9 + (double)100)
        cout << -1;
    else
        cout << fixed << setprecision(20) << l;
    return 0;
}