#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void No()
{
    puts("NO");
    exit(0);
}

string merge(string s, string t, char c)
{
    int i = 0, j = 0;
    while (s[i] != c) i++;
    while (t[j] != c) j++;
    int l = 1;
    while (i + l < s.length() and j + l < t.length())
    {
        if (s[i + l] != t[j + l]) return "";
        l++;
    }
    l = 1;
    while (i - l >= 0 and j - l >= 0)
    {
        if (s[i - l] != t[j - l]) return "";
        l++;
    }
    if (i > j)
    {
        swap(i, j);
        swap(s, t);
    }
    string ret = t;
    ret.resize(max(ret.size(), s.size() + j - i));
    REP(k, s.size()) ret[k + j - i] = s[k];
    return ret;
}

bool is_bad(const string &s)
{
    array<int, 26> cnt;
    cnt.fill(0);
    for (auto c : s) cnt[c - 'a']++;
    return (*max_element(cnt.begin(), cnt.end()) > 1);
}

int main()
{
    int N;
    cin >> N;
    set<string> S;
    while (N--)
    {
        string str;
        cin >> str;
        if (is_bad(str)) No();
        S.insert(str);
    }

    while (true)
    {
        vector<int> cnt(26);
        for (auto str : S) for (auto c : str) cnt[c - 'a']++;
        if (*max_element(cnt.begin(), cnt.end()) <= 1)
        {
            string ret;
            for (auto str : S) ret += str;
            cout << ret << '\n';
            return 0;
        }

        int j = 0;
        while (cnt[j] <= 1) j++;
        vector<string> v;
        for (auto str : S)
        {
            bool f = false;
            for (auto c : str) if (c == 'a' + j) f = true;
            if (f) v.emplace_back(str);
        }
        for (auto s : v) S.erase(s);
        string tmp = v[0];
        for (auto str : v)
        {
            tmp = merge(tmp, str, 'a' + j);
            if (tmp.empty()) No();
            if (is_bad(tmp)) No();
        }
        S.insert(tmp);
    }
}