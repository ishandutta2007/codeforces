#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read() {
    int x = 0, f = 1, c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') f = 0;
    for (; isdigit(c);c = getchar()) x = x * 10 + c - 48;
    return f ? x : -x;
}
const int N = 3e5 + 5;
int a[N], ps[N], b[N];
vector <pair <int, int> > ans;
void Swap(int i, int j) {
    ans.emplace_back(i, j);
    swap(a[i], a[j]);
    ps[a[i]] = i;
    ps[a[j]] = j;
}
int main() {
    int n = read();
    for (int i = 0; i < n; ++ i) {
        a[i] = read() - 1;
        b[i] = a[i];
        ps[a[i]] = i;
    }
    int nn = n / 2;
    for (int i = 0; i < nn; ++ i) {
        if (ps[i] == i) continue;
        if (ps[i] - i < nn) {
            if (n - 1 - ps[i] < nn) {
                int old = ps[i];
                Swap(ps[i], 0);
                Swap(0, n - 1);
                Swap(old, 0);
            } else {
                Swap(ps[i], n - 1);
            }
        }
        Swap(ps[i], i);
    }
    for (int i = nn; i < n; ++ i) {
        if (ps[i] == i) continue;
        int old = ps[i];
        Swap(ps[i], 0);
        Swap(0, i);
        Swap(old, 0);
    }
    printf("%d\n", (int) ans.size());
    for (int i = 0; i < ans.size(); ++ i) {
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
        // swap(b[ans[i].first], b[ans[i].second]);
    }
    // for (int i = 0; i < n; ++ i) cerr << b[i] << " "; cerr << endl;
    return 0;
}