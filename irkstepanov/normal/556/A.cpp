#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int a = 0, b = 0;
    forn(i, n) {
        if (s[i] == '0') {
            ++a;
        } else {
            ++b;
        }
    }

    int d = min(a, b);
    cout << max(a - d, b - d) << "\n";

}