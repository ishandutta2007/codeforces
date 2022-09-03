#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)



int main()
{
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    string ret;
    cout << "YES" << endl;

    REP(_, 2)
    {
        if (S[0] == S[1])
        {
            if (T[0] == T[1])
            {
                REP(_, N) ret += "abc";
                cout << ret << endl;
                return 0;
            }
            else
            {
                string s;
                s += T[1];
                s += T[0];
                s += (char)('a' + 'b' + 'c' - T[0] - T[1]);
                REP(_, N) ret += s;
                cout << ret << endl;
                return 0;
            }
        }
        swap(S, T);
    }

    if (S == T)
    {
        string s;
        s += T[1];
        s += T[0];
        s += (char)('a' + 'b' + 'c' - T[0] - T[1]);
        REP(_, N) ret += s;
        cout << ret << endl;
        return 0;
    }

    if (S[0] == T[0])
    {
        REP(_, N) ret += S[1];
        REP(_, N) ret += T[1];
        REP(_, N) ret += T[0];
        cout << ret << endl;
        return 0;
    }

    if (S[1] == T[1])
    {
        REP(_, N) ret += T[1];
        REP(_, N) ret += S[0];
        REP(_, N) ret += T[0];
        cout << ret << endl;
        return 0;
    }

    if (S[0] == T[1] and T[0] == S[1])
    {
        REP(_, N) ret += T[0];
        REP(_, N) ret += (char)('a' + 'b' + 'c' - T[0] - T[1]);
        REP(_, N) ret += T[1];
        cout << ret << endl;
        return 0;
    }

    REP(_, 2)
    {
        if (S[1] != T[0])
        {
            REP(_, N) ret += S[1];
            REP(_, N) ret += S[0];
            REP(_, N) ret += T[0];
            cout << ret << endl;
            return 0;
        }
        swap(S, T);
    }
}