#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int nmax = (int)(1e6 + 5);

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("mine.txt", "w", stdout);

    char a[nmax], b[nmax];
    scanf("%s", a);
    scanf("%s", b);

    int x = 0;
    for (; a[x] == '0'; ++x) ;
    int y = 0;
    for (; a[y]; ++y) ;

    int u = 0;
    for (; b[u] == '0'; ++u) ;
    int v = 0;
    for (; b[v]; ++v);

    if (y - x > v - u) {
        cout << ">\n";
        return 0;
    }
    if (y - x < v - u) {
        cout << "<\n";
        return 0;
    }

    for (; x != y; ++x, ++u) {
        if (a[x] < b[u]) {
            cout << "<\n";
            return 0;
        }
        if (a[x] > b[u]) {
            cout << ">\n";
            return 0;
        }
    }
    cout << "=\n";

}