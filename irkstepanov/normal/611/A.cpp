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
    //ofstream cout("output.txt");

    int a;
    string x, y;
    cin >> a >> x >> y;

    if (y == "week") {
        if (a != 5 && a != 6) {
            cout << "52\n";
        } else {
            cout << "53\n";
        }
        return 0;
    }

    if (a <= 29) {
        cout << "12\n";
        return 0;
    }

    if (a == 30) {
        cout << "11\n";
    } else {
        cout << "7\n";
    }

}