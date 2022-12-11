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

    bool flag = false;
    while (n--) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        if (x >= 2400 && y > x) {
            flag = true;
        }
    }

    cout << (flag ? "YES\n" : "NO\n");

}