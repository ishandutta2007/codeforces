#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a[5];
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }

    map<string, int> id;
    id["S"] = 0;
    id["M"] = 1;
    id["L"] = 2;
    id["XL"] = 3;
    id["XXL"] = 4;

    vector<string> vct = {"S", "M", "L", "XL", "XXL"};

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int x = id[s];
        //cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << endl;
        for (int i = 0; ; ++i) {
            if (x + i < 5 && a[x + i]) {
                cout << vct[i + x] << '\n';
                --a[i + x];
                break;
            }
            if (x - i >= 0 && a[x - i]) {
                cout << vct[x - i] << '\n';
                --a[x - i];
                break;
            }
        }
    }
    

}