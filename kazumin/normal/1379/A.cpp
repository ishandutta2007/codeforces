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

string t = "abacaba";

int check(string s, int idx) {
    int check = 0;
    for (int i = idx; i < idx + 7; i++) {
        if (i < s.size() && s[i] == '?') check++;
        if (i < s.size() && (s[i] == t[i - idx])) continue;
        return 0;
    }
    //if (check == 0) return 2;
    return 1;
}

int checkq(string s, int idx) {
    int check = 0;
    for (int i = idx; i < idx + 7; i++) {
        if (i < s.size() && s[i] == '?') check++;
        if (i < s.size() && (s[i] == t[i - idx] || s[i] == '?')) continue;
        return 0;
    }
    //if (check == 0) return 2;
    return 1;
}

int sett(string &s, int idx) {
    for (int i = idx; i < idx + 7; i++) {
        s[i] = t[i - idx];
    }
    return 1;
}

int main() {
    boost();

    int T;
    cin >> T;
    outer:
    while (T--) {
        int n;
        string s, ss;
        cin >> n >> s;
        ss = s;
        for (int i = 0; i < n; i++) {
            if (checkq(ss, i)) {
                sett(ss, i);
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (check(ss, j)) cnt++;
                }
                if (cnt == 1) {
                    printf("Yes\n");
                    for (int j = 0; j < n; j++) {
                        if (ss[j] == '?') printf("z");
                        else printf("%c", ss[j]);
                    }
                    printf("\n");
                    goto outer;
                }
            }
            ss = s;
        }
        ss = s;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (check(ss, j)) cnt++;
        }
        if (cnt == 1) {
            printf("Yes\n");
            for (int j = 0; j < n; j++) {
                if (ss[j] == '?') printf("z");
                else printf("%c", ss[j]);
            }
            printf("\n");
            goto outer;
        }
        printf("No\n");
    }

    return 0;
}