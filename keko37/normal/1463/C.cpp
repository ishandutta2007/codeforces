#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;
const llint INF = 1000000000000000000LL;

llint tt, n;
llint curr_pos = 0, curr_t = 0, target = 0;
llint t[MAXN], x[MAXN];

void idi (llint val) {
    curr_t += val;
    if (curr_pos < target) curr_pos += val; else curr_pos -= val;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t[i] >> x[i];
        }
        t[n] = INF;
        curr_pos = 0, curr_t = 0, target = 0;
        int ind = 0, sol = 0;
        while (ind < n) {
            llint ost_dist = abs(target - curr_pos);
            llint ost_t = t[ind] - curr_t;
            if (ost_dist > 0 && ost_t > 0) {
                idi(min(ost_dist, ost_t));
            } else if (ost_t == 0) {
                if (ost_dist == 0) target = x[ind];
                llint have = t[ind + 1] - t[ind];
                if (min(curr_pos, target) <= x[ind] && x[ind] <= max(curr_pos, target) && abs(x[ind] - curr_pos) <= have) sol++;
                ind++;
            } else {
                curr_t += ost_t;
            }
        }
        cout << sol << '\n';
    }
    return 0;
}