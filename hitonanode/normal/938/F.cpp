#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int main() {
    string S;
    cin >> S;
    const int dd = __lg(S.size());

    string ret;
    vector<int> mvs{0};
    REP(t, S.size() - (1 << dd) + 1) {
        vector<int> go(1 << dd);
        for (auto x : mvs) go.at(x) = 1;
        REP(s, go.size()) {
            if (!go[s]) continue;
            REP(d, dd) {
                if (((s >> d) & 1) == 0) go[s + (1 << d)] = 1;
            }
        }
        char cmin = 'z' + 1;
        REP(i, go.size()) {
            if (go[i]) cmin = min(cmin, S[t + i]);
        }
        ret += cmin;
        mvs.clear();
        REP(i, go.size()) {
            if (go[i] and S[t + i] == cmin) mvs.push_back(i);
        }
    }
    cout << ret << '\n';
}