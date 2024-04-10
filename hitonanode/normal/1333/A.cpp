#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> ret(N, string(M, 'B'));
        ret[0][0] = 'W';
        for (auto s : ret) printf("%s\n", s.c_str());
    }
}