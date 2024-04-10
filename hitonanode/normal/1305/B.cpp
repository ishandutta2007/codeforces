#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<int> solve(string &S) {
    if (S.empty()) return {};
    vector<int> ret;
    int l = 0, r = int(S.length()) - 1;
    while (r > l) {
        while (l < S.length() and S[l] == ')') l++;
        while (r >= 0 and S[r] == '(') r--;
        if (r <= l) break;
        ret.push_back(l);
        ret.push_back(r);
        l++;
        r--;
    }
    sort(ret.rbegin(), ret.rend());
    for (auto x : ret) S.erase(S.begin() + x);
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    string S;
    cin >> S;
    vector<vector<int>> ret;
    while (true) {
        vector<int> tmp = solve(S);
        if (tmp.empty()) break;
        ret.push_back(tmp);
    }
    printf("%d\n", int(ret.size()));
    for (auto v : ret) {
        printf("%d\n", v.size());
        for (auto x : v) printf("%d ", x + 1);
        puts("");
    }
}