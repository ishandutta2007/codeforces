#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (v[i] == '>') {
            d[i] = x;
        } else {
            d[i] = -x;
        }
    }

    int pos = 0;
    for (int step = 0; step < 2 * n; ++step) {
        pos += d[pos];
        if (pos < 0 || pos >= n) {
            cout << "FINITE\n";
            return 0;
        }
    }

    cout << "INFINITE\n";

}