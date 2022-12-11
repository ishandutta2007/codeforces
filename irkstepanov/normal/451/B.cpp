#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int main()
{

    int n;
    cin >> n;

    vector <int> v(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    a = v;
    sort(a.begin(), a.end());

    vector <int> bad;

    for (int i = 0; i < n; i++)
        if (a[i] != v[i]) bad.pb(i);

    if (bad.size() == 0) {cout << "yes\n" << "1 1"; return 0;}

    int l = bad[0], r = bad.back();
    while (l < r)
    {
        swap(v[l], v[r]);
        ++l, --r;
    }

    for (int i = 0; i < n; i++)
        if (v[i] != a[i]) {cout << "no"; return 0;}

    cout << "yes\n" << bad[0] + 1 << " " << bad.back() + 1;

}