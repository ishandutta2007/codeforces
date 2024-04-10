#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

string s;
int m, b[55];
char ans[55];

int cnt(char c, vector<char> &v) {
    int ret = 0;
    for (char p : v) if (p == c) ret++;
    return ret;
}

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> s >> m;
        vector<char> v;
        for (char c : s) v.push_back(c);
        sort(v.begin(), v.end());
        for (int i = 1; i <= m; i++) cin >> b[i];
        //for (char c : v) printf("%c ", c); printf("\n");
        while (1) {
            vector<int> id;
            for (int i = 1; i <= m; i++) if (!b[i]) id.push_back(i);
            if (id.empty()) break;
            char c = v.back();
            while (cnt(c, v) < id.size()) {
                while (v.back() == c) v.pop_back();
                c = v.back();
            }
            for (int p : id) {
                //printf("%d\n", p);
                ans[p] = v.back();
                v.pop_back();
                for (int i = 1; i <= m; i++) b[i] -= abs(p - i);
                b[p] = -9999;
            }
            while (v.back() == c) v.pop_back();
        }
        //printf("here\n");
        for (int i = 1; i <= m; i++) printf("%c", ans[i]);
        printf("\n");
    }

    return 0;
}