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

    string s;
    cin >> s;

    int cnt = 0;
    int n = sz(s);

    for (char c = 'a'; c <= 'z'; ++c) {
        vector<int> pos;
        for (int i = 0; i < sz(s); ++i) {
            if (s[i] == c) {
                pos.pb(i);
            }
        }
        if (pos.empty()) {
            continue;
        }
        /*if (sz(pos) == 1) {
            ++cnt;
            continue;
        }*/
        int best = 0;
        for (int d = 1; d < n; ++d) {
            map<char, int> mapa;
            for (int x : pos) {
                ++mapa[s[(x + d) % n]];
            }
            int curr = 0;
            for (auto it : mapa) {
                if (it.second == 1) {
                    ++curr;
                }
            }
            best = max(best, curr);
        }
        cnt += best;
    }

    cout << fixed;
    cout.precision(20);
    cout << ld(cnt) / n << endl;

}