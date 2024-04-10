#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd "\n"; return 0;
#define all(v) v.begin(), v.end()
#define double long double

using namespace std;

const int MAXN = 1e3;
const int INF = 1e18;
const int MOD = 1e9 + 7;

pr<double, double> a[MAXN];

double rastt(int x, int y){
    return sqrt((a[x].fs - a[y].fs) * (a[x].fs - a[y].fs) + (a[x].sc - a[y].sc) * (a[x].sc - a[y].sc));
}

double plosh(int x, int y, int z){
    return abs((a[y].fs - a[x].fs) * (a[z].sc - a[x].sc) - (a[y].sc - a[x].sc) * (a[z].fs - a[x].fs)) / 2.0;
}

main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].fs >> a[i].sc;
    }
    double rast = INF;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j){
                rast = min(rast, rastt(i, j) / 2.0);
            }
        }
    }
    for (int i = 0; i < n; i++){
        int x, y, z;
        x = i;
        y = (i + 1) % n;
        z = (i + 2) % n;
        rast = min(rast, plosh(x, y, z) / rastt(x, z));
    }
    cout << setprecision(9) << rast;
}