#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<double> a;
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    double ans = 0;
    for (int st = 0; st < n; ++st) {
        double res = 0;
        double none = 1;

        for (int i = st; i < n; ++i) {
            double nres = res * (1. - a[i]) + none * a[i];
            double nnone = none * (1. - a[i]);
            res = nres;
            none = nnone;
            ans = max(ans, res);
        }
    }

    cout.precision(15);
    cout << fixed << ans << endl;


    return 0;
}