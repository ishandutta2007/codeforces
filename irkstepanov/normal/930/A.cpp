#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __ll128 bigll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> parent(n);
    vector<int> depth(n);

    for (int i = 1; i < n; ++i) {
        cin >> parent[i];
        --parent[i];
        depth[i] = depth[parent[i]] + 1;
    }

    map<int, int> mapa;
    for (int i = 0; i < n; ++i) {
        ++mapa[depth[i]];
    }

    int ans = 0;
    for (auto it : mapa) {
        if (it.second % 2) {
            ++ans;
        }
    }
    cout << ans << "\n";

}