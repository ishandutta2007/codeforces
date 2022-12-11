#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("correct.txt");

    int n;
    cin >> n;

    vector<string> a(n);
    forn(i, n) {
        cin >> a[i];
        if (a[i] == "0") {
            cout << "0\n";
            return 0;
        }
    }

    string ans = "";
    int cnt = 0;

    forn(i, n) {
        bool ok = true;
        if (a[i][0] != '1') {
            ok = false;
        }
        for (int j = 1; j < sz(a[i]); ++j) {
            if (a[i][j] != '0') {
                ok = false;
            }
        }
        if (ok) {
            cnt += sz(a[i]) - 1;
            continue;
        } else {
            ans = a[i];
        }
    }

    if (ans == "") {
        ans = "1";
    }
    cout << ans;
    forn(i, cnt) {
        cout << '0';
    }

}