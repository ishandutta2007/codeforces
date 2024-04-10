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
typedef pair<int, int> pii;

struct pt
{
    int x, y;
};

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    pt a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    if (a.x == b.x && a.x == c.x) {
        cout << "1\n";
        return 0;
    }

    if (a.y == b.y && a.y == c.y) {
        cout << "1\n";
        return 0;
    }

    if (a.x == b.x && (c.y >= max(a.y, b.y) || c.y <= min(a.y, b.y))) {
        cout << "2\n";
        return 0;
    }

    if (a.y == b.y && (c.x >= max(a.x, b.x) || c.x <= min(a.x, b.x))) {
        cout << "2\n";
        return 0;
    }

    if (a.x == c.x && (b.y >= max(a.y, c.y) || b.y <= min(a.y, c.y))) {
        cout << "2\n";
        return 0;
    }

    if (a.y == c.y && (b.x >= max(a.x, c.x) || b.x <= min(a.x, c.x))) {
        cout << "2\n";
        return 0;
    }

    if (b.x == c.x && (a.y >= max(b.y, c.y) || a.y <= min(b.y, c.y))) {
        cout << "2\n";
        return 0;
    }

    if (b.y == c.y && (a.x >= max(b.x, c.x) || a.x <= min(b.x, c.x))) {
        cout << "2\n";
        return 0;
    }

    cout << "3\n";

}