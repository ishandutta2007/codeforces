#include<iostream>
#include<vector>
using namespace std;

double abs(double x) {
    return (x > 0) ? (x) : (-x);
};

int main() {
    long n, T, tmp, m;
    double c;
    cin >> n >> T >> c;
    vector<long> a, p;
    for (long i = 0; i < n; ++i) {
        cin >> tmp;
        a.push_back(tmp);
    };
    cin >> m;
    for (long i = 0; i < m; ++i) {
        cin >> tmp;
        p.push_back(tmp);
    };
    long long s = 0;
    double mean = 0.0;
    for (long i = 0; i < T; ++i) {
        s += a[i];
        mean = (mean + double(a[i]) / double(T)) / double(c);
    };
    long num = 0;
    for (long i = T; i < n; ++i) {
        if (p[num] == i) {
            cout << double(s) / T << ' ' << mean << ' ' << abs(double(s) / T - mean) / (double(s) / T) << endl;
            if (num < m - 1) ++num;
        };
        s += a[i];
        s -= a[i - T];
        mean = (mean + double(a[i]) / double(T)) / double(c);
    };
    if (p[num] == n)
        cout << double(s) / T << ' ' << mean << ' ' << abs(double(s) / T - mean) / (double(s) / T) << endl;
};