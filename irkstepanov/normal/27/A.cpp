#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 3050;

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> cnt(nmax);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }

    for (int i = 1; i < nmax; ++i) {
        if (!cnt[i]) {
            cout << i << "\n";
            return 0;
        }
    }

}