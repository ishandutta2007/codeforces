#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;



int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    cin >> S;

    vector can(2 * N - 1, vector<int>(2 * N - 1));
    vector bad(2 * N - 1, vector<int>(2 * N - 1));
    set<pint> bads;
    REP(i, N) REP(j, N) if (S[i][j] == 'o')
    {
        REP(ii, N) REP(jj, N) if (S[ii][jj] == '.')
        {
            bad[ii - i + (N - 1)][jj - j + (N - 1)] = 1;
            bads.emplace(ii - i, jj - j);
        }
    }
    vector<string> T(N, string(N, '.'));
    REP(i, N) REP(j, N) if (S[i][j] == 'o') T[i][j] = 'o';
    REP(i, N) REP(j, N) if (T[i][j] == 'o')
    {
        REP(ii, N) REP(jj, N) if (T[ii][jj] == '.' and !bads.count(pint(ii - i, jj - j)))
        {
            T[ii][jj] = 'x';
        }
    }
    if (T == S)
    {
        cout << "YES\n";
        REP(x, 2 * N - 1)
        {
            REP(y, 2 * N - 1)
            {
                if (x == N - 1 and y == N - 1)
                {
                    cout << 'o';
                }
                else
                {
                    if (bads.count(pint(x - (N - 1), y - (N - 1)))) cout << '.';
                    else cout << 'x';
                }
                
            }
            cout << '\n';
        }
    }
    else
    {
        puts("NO");
    }
}