#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 18;

int n;
int cnt[mxn];

int main() {
    scanf("%d", &n);
    rep(i, n) {
        int a;
        scanf("%d", &a);
        cnt[a] += 1;
    }
    std::vector <int> ans;
#define update(v) { if ((v).size() > ans.size()) ans = (v); }
    rep(x, mxn) {
        if (cnt[x]) {
            std::vector <int> s;
            rep(i, cnt[x]) s.push_back(x);
            update(s);
        }
        int y = x + 1;
        if (cnt[x] && cnt[y]) {
            std::vector <int> s;
            rep(i, cnt[x]) s.push_back(x);
            rep(i, cnt[y]) s.push_back(y);
            update(s);
        }
    }
    rep(S, mxn) {
        if (cnt[S] >= 2) {
            int T;
            for (T = S; T < mxn && cnt[T] >= 2; ++ T);
            -- T;
            int a = S;
            if (cnt[S - 1] >= 1) -- a;
            int b = T;
            if (cnt[T + 1] >= 1) ++ b;
            if (a + 1 <= b - 1) {
                std::vector <int> s;
                rep(i, cnt[a]) s.push_back(a);
                for (int x = a + 1; x <= b - 1; ++ x) {
                    rep(i, cnt[x] - 1) s.push_back(x);
                }
                rep(i, cnt[b]) s.push_back(b);
                for (int x = b - 1; x >= a + 1; -- x) {
                    rep(i, 1) s.push_back(x);
                }
                update(s);
            }
            S = T;
        }
    }
    printf("%d\n", (int) ans.size());
    rep(i, ans.size()) printf("%d ", ans[i]);
    printf("\n");
	return 0;
}