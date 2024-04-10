#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read() {
    int x = 0, f = 1, c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') f = 0;
    for (; isdigit(c);c = getchar()) x = x * 10 + c - 48;
    return f ? x : -x;
}
int n;
vector <pair <pair <int, int>, int> > va, vb;
void solve(vector <pair <pair <int, int>, int> > & v, vector <int> & ans) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++ i) {
        ans.push_back(v[i].second);
    }
}
int main() {
    n = read();
    for (int i = 0; i < n; ++ i) {
        int a = read(), b = read();
        if (a < b) va.emplace_back(make_pair(-b, a), i);
        else vb.emplace_back(make_pair(b, a), i);
    }
    vector <int> ansa, ansb, ans;
    solve(va, ansa);
    solve(vb, ansb);
    if (ansa.size() > ansb.size()) ans = ansa;
    else ans = ansb;
    printf("%d\n", (int) ans.size());
    for (int i = 0; i < ans.size(); ++ i) {
        printf("%d", ans[i] + 1);
        putchar(i + 1 == ans.size() ? 10 : 32);
    }
    return 0;
}