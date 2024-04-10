#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int main()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<vector<int>> ret;
    while (true) {
        vector<int> v;
        REP(i, N - 1) {
            if (S[i] == 'R' and S[i + 1] == 'L') {
                v.emplace_back(i + 1);
                swap(S[i], S[i + 1]);
                i++;
            }
        }
        if (v.size()) ret.push_back(v);
        else break;
    }

    int tr = 0;
    for (auto v : ret) tr += v.size();
    if (tr < K or ret.size() > K) {
        puts("-1");
        return 0;
    }

    int la = K - ret.size();
    for (auto vec : ret) {
        int i = 0;
        while (la and i + 1 < vec.size()) {
            printf("1 %d\n", vec[i]);
            la--;
            i++;
        }
        printf("%d", int(vec.size()) - i);
        FOR(j, i, vec.size()) {
            printf(" %d", vec[j]);
        }
        puts("");
    }
}