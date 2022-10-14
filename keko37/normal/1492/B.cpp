#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n;
int p[MAXN], bio[MAXN];
vector <int> v, tmp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            bio[i] = 0;
        }
        v.clear(); tmp.clear();
        int curr = n;
        for (int i = n; i >= 1; i--) {
            bio[p[i]] = 1;
            tmp.push_back(p[i]);
            if (p[i] == curr) {
                while (!tmp.empty()) {
                    v.push_back(tmp.back());
                    tmp.pop_back();
                }
                while (bio[curr] == 1) curr--;
            }
        }
        for (auto x : v) cout << x << " "; cout << '\n';
    }
    return 0;
}