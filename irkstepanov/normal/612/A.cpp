#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    int a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    for (int x = 0; x < 200; ++x) {
        int y = n - a * x;
        if (y < 0 || y % b) {
            continue;
        }
        y /= b;
        cout << x + y << "\n";
        int pos = 0;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < a; ++j) {
                cout << s[pos++];
            }
            cout << "\n";
        }
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < b; ++j) {
                cout << s[pos++];
            }
            cout << "\n";
        }
        return 0;
    }

    cout << "-1\n";

}