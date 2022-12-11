#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

int main()
{

    int n;
    cin >> n;

    int curr = 1;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (curr == a) {
            ans.pb(2000 + i);
            curr = a + 1;
        }
    }
    cout << sz(ans) << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

}