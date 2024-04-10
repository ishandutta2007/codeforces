#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    string s;
    cin >> s;

    bool all_a = true;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] != 'a') {
            all_a = false;
            break;
        }
    }

    if (all_a) {
        s[sz(s) - 1] = 'z';
        cout << s << "\n";
        return 0;
    }

    int lf, rg;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] != 'a') {
            lf = i;
            break;
        }
    }
    rg = lf;
    while (rg + 1 < sz(s) && s[rg + 1] != 'a') {
        ++rg;
    }

    for (int i = 0; i < sz(s); ++i) {
        if (i >= lf && i <= rg) {
            cout << (char)(s[i] - 1);
        } else {
            cout << s[i];
        }
    }
    cout << "\n";

}