#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
    int n;
    scanf("%d", &n);
    vector <pair <int, int> > s(n);
    rep(i, n) scanf("%d %d", &s[i].first, &s[i].second);
    vector <int> v;
    rep(i, n) {
        v.pb(s[i].first - 1);
        v.pb(s[i].first);
        v.pb(s[i].second);
        v.pb(s[i].second + 1);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    rep(i, n) {
        s[i].first = lower_bound(v.begin(), v.end(), s[i].first) - v.begin();
        s[i].second = lower_bound(v.begin(), v.end(), s[i].second) - v.begin();
    }
    vector <int> C(v.size());
    rep(i, n) {
        C[s[i].first] ++;
        C[s[i].second + 1] --;
    }
    rep(i, v.size()) {
        if (i) C[i] += C[i - 1];
    }
    vector <int> S(v.size());
    rep(i, v.size()) {
        S[i] = C[i] == 1;
    }
    rep(i, v.size()) {
        if (i) S[i] += S[i - 1];
    }
    rep(i, n) {
        if (S[s[i].second] - S[s[i].first - 1] == 0) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}