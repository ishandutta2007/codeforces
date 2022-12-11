#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n;
    cin >> n;

    int r = 0, g = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'R') {
            ++r;
        }
        if (c == 'G') {
            ++g;
        }
        if (c == 'B') {
            ++b;
        }
    }

    if (r && g && b) {
        cout << "BGR\n";
        return 0;
    }

    if (r && g) {
        cout << "B";
        if (r > 1) {
            cout << "G";
        }
        if (g > 1) {
            cout << "R";
        }
        cout << "\n";
        return 0;
    }

    if (r && b) {
        if (r > 1) {
            cout << "B";
        }
        cout << "G";
        if (b > 1) {
            cout << "R";
        }
        cout << "\n";
        return 0;
    }

    if (b && g) {
        if (g > 1) {
            cout << "B";
        }
        if (b > 1) {
            cout << "G";
        }
        cout << "R";
        cout << "\n";
        return 0;
    }

    if (r) {
        cout << "R";
    } else if (g) {
        cout << "G";
    } else {
        cout << "B";
    }
    cout << "\n";

}