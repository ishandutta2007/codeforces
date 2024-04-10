#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int solve()
{
    int N;
    cin >> N;
    vector<int> v(2);
    int ki = 0;
    REP(_, N)
    {
        string S;
        cin >> S;
        if ((int)S.length() % 2) ki++;
        for (auto c : S) v[c - '0']++;
    }
    if (!ki and v[0] % 2) return N - 1;
    else return N;
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        cout << solve() << endl;
    }
}