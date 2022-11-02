#include <bits/stdc++.h>
using namespace std;
int m, n;
const int N = 60;
struct P {
    int x, y, i;
} S[N], T[N];
int tar[N], aaa[N];
std::vector<std::pair<P, P> > Sp, Md, Tp;
void mv(P &w, P t, std::vector<std::pair<P, P> > &Sp) {
    P v;
    while (w.x < t.x) v = w, ++w.x, Sp.push_back(make_pair(v, w));
    while (w.x > t.x) v = w, --w.x, Sp.push_back(make_pair(v, w));
    while (w.y < t.y) v = w, ++w.y, Sp.push_back(make_pair(v, w));
    while (w.y > t.y) v = w, --w.y, Sp.push_back(make_pair(v, w));
}

void solve(P S[], std::vector<std::pair<P, P> > &Sp) {
    sort(S + 1, S + m + 1, [](P a, P b) { return (a.x == b.x ? a.y < b.y : a.x < b.x); });
    for (int i = 1, j = 1; i <= m; i = j + 1) {
        j = max(j, i);
        while (j < m && S[j + 1].x == S[j].x) ++j;
        while (1) {
            int fl = 0;
            for (int p = i; p <= j; ++p) {
                while (p < S[p].y && ((p == i) || (S[p - 1].y != S[p].y - 1))) {
                    mv(S[p], (P){S[p].x, S[p].y - 1, S[i].i}, Sp), fl = 1;
                }
                while (p > S[p].y && ((p == j) || (S[p + 1].y != S[p].y + 1))) {
                    mv(S[p], (P){S[p].x, S[p].y + 1, S[i].i}, Sp), fl = 1;
                }
            }
            if (!fl) break;
        }
    }
    for (int i = 1; i <= m; ++i) mv(S[i], (P){i, i, S[i].i}, Sp);
}

void tern(int j, std::vector<std::pair<P, P> > &Md) {
    swap(aaa[j], aaa[j - 1]);
    Md.push_back(make_pair((P){j - 1, j - 1, -1}, (P){j - 1, j, -1}));
    Md.push_back(make_pair((P){j, j, -1}, (P){j, j - 1, -1}));
    Md.push_back(make_pair((P){j - 1, j, -1}, (P){j, j, -1}));
    Md.push_back(make_pair((P){j, j - 1, -1}, (P){j - 1, j - 1, -1}));
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) scanf("%d%d", &S[i].x, &S[i].y), S[i].i = i;
    for (int i = 1; i <= m; ++i) scanf("%d%d", &T[i].x, &T[i].y), T[i].i = i;
    solve(S, Sp);
    solve(T, Tp);
    for (int i = 1; i <= m; ++i) tar[T[i].i] = T[i].x;
    for (int i = 1; i <= m; ++i) aaa[S[i].x] = tar[S[i].i];
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j > 1; --j) {
            if (aaa[j] > aaa[j - 1]) break;
            tern(j, Md);
        }
    }
    printf("%d\n", Sp.size() + Tp.size() + Md.size());
    for (int i = 0; i < Sp.size(); ++i) {
        printf("%d %d %d %d\n", Sp[i].first.x, Sp[i].first.y, Sp[i].second.x, Sp[i].second.y);
    }
    for (int i = 0; i < Md.size(); ++i) {
        printf("%d %d %d %d\n", Md[i].first.x, Md[i].first.y, Md[i].second.x, Md[i].second.y);
    }
    for (int i = Tp.size() - 1; ~i; --i) {
        printf("%d %d %d %d\n", Tp[i].second.x, Tp[i].second.y, Tp[i].first.x, Tp[i].first.y);
    }
    return 0;
}