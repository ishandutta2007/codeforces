#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    set<pair<int, int>> s;

    vector<int> nxt(n);
    vector<int> pos(n, n);
    for (int i = n - 1; i >= 0; --i) {
        nxt[i] = pos[a[i]];
        pos[a[i]] = i;
    }

    vector<int> cur(n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!s.count({cur[a[i]], a[i]})) {
            ++ans;
            if (sz(s) == k) {
                s.erase(--s.end());
            }
        }

        s.erase({cur[a[i]], a[i]});
        cur[a[i]] = nxt[i];
        s.insert({cur[a[i]], a[i]});
    }

    cout << ans << endl;
}