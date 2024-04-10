#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");

    int n, s;
    cin >> n >> s;

    set<int> used;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        used.insert(x);
    }

    vector<int> ans;

    for (int i = 1; i <= s; ++i) {
        if (!used.count(i)) {
            ans.pb(i);
            s -= i;
        }
    }

    cout << sz(ans) << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

}