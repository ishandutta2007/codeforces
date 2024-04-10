#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

void bad()
{
    puts("NO");
    exit(0);
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N;
    cin >> N;
    if (N == 1) {
        cout << "YES\n1\n1 2 3\n";
        return 0;
    }
    if (N % 2) {
        cout << "YES\n" << N - 1 << '\n';
        REP(i, N / 2) {
            cout << i * 2 + 1 << ' ' << i * 2 + 2 << ' ' << i * 2 + 3 << '\n';
        }
        REP(i, N / 2) {
            cout << i * 2 + 1 << ' ' << i * 2 + 2 << ' ' << N << '\n';
        }
        return 0;
    }
    vector<int> A(N);
    for (auto &a : A) {
        cin >> a;
    }
    int all = 0;
    for (auto a : A) all ^= a;

    if (N % 2 == 0 and all) {
        bad();
    }

    vector<vector<int>> ret;
    ret.push_back({ 1, 2, 3 });
    for (int i = 0; i < (N - 2) / 2 - 1; i++) {
        ret.push_back({ i * 2 + 4, i * 2 + 5, i * 2 + 6 });
        ret.push_back({ 1, i * 2 + 4, i * 2 + 5 });
    }
    cout << "YES\n" << ret.size() << '\n';
    for (auto v : ret) {
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
    }
}