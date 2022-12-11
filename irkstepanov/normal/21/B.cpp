 #include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    if (a1 == 0 && b1 == 0 && c1 != 0) {
        cout << "0\n";
        return 0;
    }
    if (a2 == 0 && b2 == 0 && c2 != 0) {
        cout << "0\n";
        return 0;
    }

    if (a1 == 0 && b1 == 0) {
        cout << "-1\n";
        return 0;
    }
    if (a2 == 0 && b2 == 0) {
        cout << "-1\n";
        return 0;
    }

    int det = a1 * b2 - a2 * b1;
    if (det) {
        cout << "1\n";
        return 0;
    }

    if (a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1) {
        cout << "-1\n";
    } else {
        cout << "0\n";
    }

}