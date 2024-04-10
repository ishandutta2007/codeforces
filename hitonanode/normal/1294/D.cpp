#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int main()
{
    int Q, X;
    cin >> Q >> X;
    vector<set<int>> c2m(400001);
    vector<int> m2c(X);
    REP(m, X) c2m[0].insert(m);
    int lo = 0;

    while (Q--) {
        int y;
        cin >> y;
        y %= X;
        int c = m2c[y];
        m2c[y]++;
        c2m[c].erase(y);
        c2m[c + 1].insert(y);
        while (c2m[lo].empty()) lo++;
        printf("%d\n", *c2m[lo].begin() + lo * X);
    }
}