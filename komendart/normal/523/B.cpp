#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    double T, c;
    scanf("%d%lf%lf", &n, &T, &c);

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int m;
    scanf("%d", &m);
    vector<bool> interesting(n + 1, false);
    for (int i = 0; i < m; i++) {
        int p;
        scanf("%d", &p);
        interesting[p] = true;
    }

    double mean = 0.0;
    long long int real = 0;
    for (int i = 1; i <= n; i++) {
        mean = (mean + a[i] / T) / c;
        real += a[i];
        if (i > T) real -= a[i - T];
        if (interesting[i]) {
            double real2 = real / T;
            printf("%.9f %.9f %.9f\n", real2, mean, fabs(real2 - mean) / real2);
        }
    }
}