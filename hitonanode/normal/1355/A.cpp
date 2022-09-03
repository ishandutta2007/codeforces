#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


lint solve(lint A1, lint K)
{
    K--;
    while (K)
    {
        K--;
        string s = to_string(A1);
        sort(ALL(s));
        if (s[0] == '0') break;
        A1 += (s[0] - '0') * (s.back() - '0');
    }
    return A1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        lint A1, K;
        cin >> A1 >> K;
        cout << solve(A1, K) << '\n';
    }
}