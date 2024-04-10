#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main()
{

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    vector<int> ans(n);
    int used = 0;
    for (int i = 1; i < sz(ans); i += 2) {
        ans[i] = a[used++];
    }
    for (int i = 0; i < sz(ans); i += 2) {
        ans[i] = a[used++];
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}