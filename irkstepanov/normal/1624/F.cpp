#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int inf = 1e9 + 10;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    int z = 0;
    int lf = 1, rg = n - 1;
    while (lf != rg) {
        int md = (lf + rg) >> 1;
        int add = n - md - 1;
        cout << "+ " << add << endl;
        int val;
        cin >> val;
        if (val == z) {
            rg = md;
            lf += add;
            rg += add;
        } else {
            z = val;
            lf = md + 1;
            lf += add;
            rg += add;
            lf -= n;
            rg -= n;
        }
    }

    cout << "! " << lf + z * n << endl;

}