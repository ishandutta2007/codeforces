#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> ret;
    FOR(i, 1, N + 1) {
        int a = min((i - 1) / 2, M);
        M -= a;
        if (i <= 2) ret.push_back(i);
        else if (!a) ret.push_back(i * 1e4 + 5e8);
        else if (a == (i - 1) / 2) ret.push_back(i);
        else ret.push_back(i * 2 - a * 2 - 1);
    }
    if (M) {
        puts("-1");
    }
    else {
        for (auto x : ret) printf("%d ", x);
        puts("");
    }
}