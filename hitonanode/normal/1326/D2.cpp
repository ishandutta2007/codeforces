#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

// Manacher's Algorithm: radius of palindromes
// Input: std::string of length N
// Output: std::vector<int> of size N
// Complexity: O(N)
// Sample:
// - `sakanakanandaka` -> [1, 1, 2, 1, 4, 1, 4, 1, 2, 2, 1, 1, 1, 2, 1]
// Reference: <https://snuke.hatenablog.com/entry/2014/12/02/235837>
std::vector<int> manacher(std::string S)
{
    std::vector<int> res(S.length());
    int i = 0, j = 0;
    while (i < (int)S.size()) {
        while (i - j >= 0 and i + j < (int)S.size() and S[i - j] == S[i + j]) j++;
        res[i] = j;
        int k = 1;
        while (i - k >= 0 and i + k < (int)S.size() and k + res[i - k] < j) res[i + k] = res[i - k], k++;
        i += k, j -= k;
    }
    return res;
}

string solve()
{
    string S;
    cin >> S;
    int N = S.length();
    string T = S;
    reverse(T.begin(), T.end());
    if (S == T) return S;

    int l = 0, r = N - 1;
    while (S[l] == S[r]) l++, r--;
    string ret0 = S.substr(0, l), ret2 = S.substr(N - l);
    T = S.substr(l, N - l * 2);
    string U;
    for (auto c : T) {
        U += c;
        U += '_';
    }
    U.pop_back();
    auto man = manacher(U);
    int len = -1, b = -1, e = -1;
    REP(i, man.size()) {
        if (man[i] == i + 1 or man[i] + i == man.size()) {
            if (chmax(len, man[i])) b = i - man[i] + 1, e = i + man[i];
        }
    }

    string ret1;
    for (int i = b; i < e; i += 2) ret1 += U[i];

    return ret0 + ret1 + ret2;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string ret = solve();
        printf("%s\n", ret.c_str());
    }
}