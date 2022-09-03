#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


vector<int> solve()
{
    int N;
    cin >> N;
    if (N < 4) return {-1};
    if (N == 4) return {2, 4, 1, 3};
    vector<int> ret(N);
    int now = 0;
    while (N)
    {
        if (N % 4 == 0)
        {
            ret[now++] = N - 1;
            ret[now++] = N - 3;
            ret[now++] = N;
            ret[now++] = N - 2;
            N -= 4;
        }
        else if (N % 4 == 1)
        {
            ret[now++] = N;
            ret[now++] = N - 2;
            ret[now++] = N - 4;
            ret[now++] = N - 1;
            ret[now++] = N - 3;
            N -= 5;
        }
        else if (N % 4 == 2)
        {
            ret[now++] = N;
            ret[now++] = N - 2;
            ret[now++] = N - 5;
            ret[now++] = N - 3;
            ret[now++] = N - 1;
            ret[now++] = N - 4;
            N -= 6;
        }
        else if (N % 4 == 3)
        {
            ret[now++] = N;
            ret[now++] = N - 2;
            ret[now++] = N - 4;
            ret[now++] = N - 6;
            ret[now++] = N - 3;
            ret[now++] = N - 1;
            ret[now++] = N - 5;
            N -= 7;
        }
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        for (auto x : solve())
        {
            cout << x << ' ';
        };
        cout << '\n';
    }
}