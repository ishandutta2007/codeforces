#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    vector<int> pref(sz(b));
    int curr = 0;

    for (int i = 0; i < sz(b); ++i) {
        while (curr < sz(a) && a[curr] != b[i]) {
            ++curr;
        }
        pref[i] = curr;
        ++curr;
        if (curr > sz(a)) {
            curr = sz(a);
        }
    }

    curr = sz(a) - 1;
    vector<int> suff(sz(b));
    for (int i = sz(b) - 1; i >= 0; --i) {
        while (curr >= 0 && a[curr] != b[i]) {
            --curr;
        }
        suff[i] = curr;
        --curr;
        if (curr < -1) {
            curr = -1;
        }
    }

    int lf = -1, rg = sz(b);
    int last;

    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        bool ok = false;
        if (suff[md] >= 0) {
            ok = true;
            last = -1;
        }
        if (pref[sz(b) - md - 1] < sz(a)) {
            ok = true;
            last = sz(b) - md - 1;
        }
        for (int i = 0; i + md + 1 < sz(b); ++i) {
            if (pref[i] < suff[i + md + 1]) {
                ok = true;
                last = i;
            }
        }
        if (ok) {
            rg = md;
        } else {
            lf = md;
        }
    }

    int md = rg;
    if (suff[md] >= 0) {
        last = -1;
    }
    if (pref[sz(b) - md - 1] < sz(a)) {
        last = sz(b) - md - 1;
    }
    for (int i = 0; i + md + 1 < sz(b); ++i) {
        if (pref[i] < suff[i + md + 1]) {
            last = i;
        }
    }

    if (rg == sz(b)) {
        cout << "-\n";
        return 0;
    }

    for (int i = 0; i <= last; ++i) {
        cout << b[i];
    }
    for (int i = last + md + 1; i < sz(b); ++i) {
        cout << b[i];
    }
    cout << "\n";

}