#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(abs(a - c), abs(b - d)) << "\n";

}