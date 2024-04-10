#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

string namae(int i)
{
    string ret;
    for (auto c : to_string(i)) ret += c - '0' + 'a';
    ret[0] += 'A' - 'a';
    return ret;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<string> ret(N);
    REP(i, K - 1) ret[i] = namae(i);
    FOR(i, K - 1, N)
    {
        string s;
        cin >> s;
        if (s == "YES") ret[i] = namae(i);
        else ret[i] = ret[i - K + 1];
    }
    for (auto s : ret) cout << s << ' ';
    cout << '\n';
}