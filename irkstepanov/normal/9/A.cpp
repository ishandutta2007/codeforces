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

int gcd(int a, int b)
{
    if (a < b) {
        swap(a, b);
    }
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("division.out");

    int a, b;
    cin >> a >> b;

    int c = 0;
    for (int i = 1; i <= 6; ++i) {
        if (i >= a && i >= b) {
            ++c;
        }
    }

    int d = gcd(c, 6);
    c /= d;
    cout << c << "/" << 6 / d << "\n";

}