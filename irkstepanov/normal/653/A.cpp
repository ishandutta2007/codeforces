#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{

    int n;
    cin >> n;

    vector<int> cnt(1100);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }

    for (int i = 0; i < 1100 - 2; ++i) {
        if (cnt[i] && cnt[i + 1] && cnt[i + 2]) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

}