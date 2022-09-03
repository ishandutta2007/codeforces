#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int T;

string solve()
{
    string A;
    cin >> A;
    string GU, KI;
    for (auto c : A) if ((c - '0') % 2) KI += c;
    else GU += c;
    string ret;
    int i = 0, j = 0;
    while (true)
    {
        if (i == (int)GU.size() and j == KI.size()) break;
        if (i == (int)GU.size()) ret += KI[j++];
        else if (j == (int)KI.size()) ret += GU[i++];
        else if (GU[i] < KI[j]) ret += GU[i++];
        else ret += KI[j++];
    }
    return ret;
}

int main()
{
    cin >> T;
    REP(_, T) cout << solve() << endl;
}