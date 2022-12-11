#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int buben = 1000;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n;
    ld k;
    cin >> n >> k;

    vector<ld> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ld lf = 0, rg = 1000;
    for (int op = 0; op < buben; ++op) {
        ld md = (lf + rg) / 2;
        ld extra = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > md) {
                extra += a[i] - md;
            }
        }
        extra *= (1.0 - k / 100);
        for (int i = 0; i < n; ++i) {
            if (a[i] < md) {
                extra -= (md - a[i]);
            }
        }
        if (extra > 0) {
            lf = md;
        } else {
            rg = md;
        }
    }

    cout << fixed;
    cout.precision(20);
    cout << lf << endl;

}