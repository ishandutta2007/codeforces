#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "w", stdout);

    vector<int> d;
    vector<char> c(50, true);
    vector<int> p;
    for (int i = 2; i < 50; ++i) {
        if (c[i]) {
            p.pb(i);
            for (int j = 2 * i; j < 50; j += i) {
                c[j] = false;
            }
        }
    }

    for (int x : p) {
        cout << x << "\n";
        cout.flush();
        string s;
        cin >> s;
        if (s == "yes") {
            d.pb(x);
        }
    }

    if (sz(d) > 1) {
        cout << "composite\n";
        cout.flush();
        return 0;
    }
    if (d.empty()) {
        cout << "prime\n";
        cout.flush();
        return 0;
    }

    if (d[0] * d[0] > 100) {
        cout << "prime\n";
        return 0;
    }
    cout << d[0] * d[0] << "\n";
    cout.flush();
    string s;
    cin >> s;
    if (s == "yes") {
        cout << "composite\n";
    } else {
        cout << "prime\n";
    }

}