#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    vector<int> vals = {1200, 1400, 1600, 1800, 2000, 2200, 2400, 2700, 3000};

    int r;
    cin >> r;
    for (int i = 0; i < sz(vals); ++i) {
        if (r < vals[i]) {
            cout << vals[i] << "\n";
            return 0;
        }
    }

}