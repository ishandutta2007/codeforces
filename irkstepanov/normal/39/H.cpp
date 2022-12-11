#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    for (int i = 1; i < k; ++i) {
        for (int j = 1; j < k; ++j) {
            int val = i * j;
            vector<int> v;
            while (val) {
                v.pb(val % k);
                val /= k;
            }
            reverse(all(v));
            for (int x : v) {
                cout << x;
            }
            cout << " ";
        }
        cout << "\n";
    }

}