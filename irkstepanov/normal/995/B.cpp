#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    n *= 2;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int start = 0;
    int ans = 0;
    while (start < n) {
        if (a[start] == a[start + 1]) {
            start += 2;
            continue;
        }
        int j = start + 1;
        while (a[j] != a[start]) {
            ++j;
        }
        while (j != start + 1) {
            swap(a[j], a[j - 1]);
            ++ans;
            --j;
        }
        start += 2;
    }

    cout << ans << "\n";

}