#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > l, r;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, a;
        scanf("%d %d", &x, &a);
        if (x < 0) {
            l.emplace_back(-x, a);
        } else {
            r.emplace_back(x, a);
        }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int s = 0;
    for (int i = 0; i < min(l.size(),r.size()); i++) {
        s += l[i].second;
        s += r[i].second;
    }
    int j = min(l.size(), r.size());
    if (j < l.size()) s += l[j].second;
    if (j < r.size()) s += r[j].second;
    printf("%d\n", s);
}