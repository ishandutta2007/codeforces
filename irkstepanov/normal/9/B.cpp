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

const ld inf = 1e18;
const ld eps = 0.00000001;

bool lt(ld a, ld b)
{
    return b - a > eps;
}

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("division.out");

    int n;
    ld a, b;
    cin >> n >> a >> b;

    vector<ld> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    ld x0, y0;
    cin >> x0 >> y0;

    ld t = inf;
    ld foot = inf;
    int id;
    for (int i = 1; i < n; ++i) {
        ld relax = x[i] / a + sqrt((x0 - x[i]) * (x0 - x[i]) + y0 * y0) / b;
        if (lt(relax, t)) {
            t = relax;
            id = i;
            foot = (x0 - x[i]) * (x0 - x[i]) + y0 * y0;
            continue;
        } else if (eq(relax, t)) {
            if (lt((x0 - x[i]) * (x0 - x[i]) + y0 * y0, foot)) {
                id = i;
                foot = (x0 - x[i]) * (x0 - x[i]) + y0 * y0;
            }
        }
    }

    cout << id + 1 << "\n";

}