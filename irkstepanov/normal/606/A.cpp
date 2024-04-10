#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main()
{

    int a, b, c;
    int x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    if (a < x && b < y && c < z) {
        cout << "No\n";
        return 0;
    }

    int add = 0;
    int miss = 0;
    if (a >= x) {
        add += (a - x) / 2;
    } else {
        miss += x - a;
    }
    if (b >= y) {
        add += (b - y) / 2;
    } else {
        miss += y - b;
    }
    if (c >= z) {
        add += (c - z) / 2;
    } else {
        miss += z - c;
    }

    cout << (add >= miss ? "Yes\n" : "No\n");

}