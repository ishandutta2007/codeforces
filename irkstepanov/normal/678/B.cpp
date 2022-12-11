#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    int n;
    cin >> n;
    bool v = false;
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        v = true;
    }

    int day = 0;
    while (1) {
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            day = (day + 2) % 7;
        } else {
            day = (day + 1) % 7;
        }
        ++n;
        bool u = false;
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            u = true;
        }
        if (day == 0 && u == v) {
            cout << n << "\n";
            return 0;
        }
    }

}