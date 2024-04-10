#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
vector <int> a, b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        a.clear(); b.clear();
        int suma = 0, sumb = 0, br = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x > 0) {
                a.push_back(x);
                suma += x;
            } else if (x < 0) {
                b.push_back(x);
                sumb += -x;
            } else {
                br++;
            }
        }
        if (suma == sumb) {
            cout << "NO\n";
        } else if (suma > sumb) {
            cout << "YES\n";
            for (auto x : a) cout << x << " ";
            for (int i = 0; i < br; i++) cout << "0 ";
            for (auto x : b) cout << x << " ";
            cout << '\n';
        } else {
            cout << "YES\n";
            for (auto x : b) cout << x << " ";
            for (int i = 0; i < br; i++) cout << "0 ";
            for (auto x : a) cout << x << " ";
            cout << '\n';
        }
    }
    return 0;
}