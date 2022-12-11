#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int n;

bool ok(const vector<int>& a)
{
    forn(i, n) {
        if (a[i] != i) {
            return false;
        }
    }
    return true;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("output.txt", "w", stdout);

    cin >> n;
    vector<int> a(n);

    forn(i, n) {
        cin >> a[i];
    }

    if (ok(a)) {
        cout << "Yes\n";
        return 0;
    }

    for (int step = 0; step < n; ++step) {
        for (int i = 0; i < n; ++i) {
            if (i % 2) {
                --a[i];
                if (a[i] == -1) {
                    a[i] = n - 1;
                }
            } else {
                ++a[i];
                if (a[i] == n) {
                    a[i] = 0;
                }
            }
        }
        if (ok(a)) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

}