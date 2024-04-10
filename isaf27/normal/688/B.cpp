#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    /*#define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout);*/
    string s;
    cin >> s;
    string e = s;
    reverse(e.begin(), e.end());
    cout << s << e;
    return 0;
}