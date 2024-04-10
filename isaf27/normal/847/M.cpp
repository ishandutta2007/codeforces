#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 1;

int a[MAXN];
vector <int> v;

int main()
{   /*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout); /**/

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++)
        v.push_back(a[i] - a[i - 1]);
    for (int i = 1; i < (int)v.size(); i++)
        if (v[i] != v[i - 1]) {
            cout << a[n - 1] << endl;
            return 0;
        }
    cout << a[n - 1] + a[n - 1] - a[n - 2] << endl;

    return 0;
}