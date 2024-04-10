#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-9;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 1e9 + 7; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18);
const int B = (int)sqrt(M);
const int X = 1e4 + 239;

string sum(string s, string t)
{
    vector<int> ans(max((int)s.size(), (int)t.size()) + 1, 0);
    for (int i = (int)s.size() - 1; i >= 0; i--)
        ans[(int)s.size() - 1 - i] += s[i] - '0';
    for (int i = (int)t.size() - 1; i >= 0; i--)
        ans[(int)t.size() - 1 - i] += t[i] - '0';
    int p = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        int ost = (p + ans[i]) % 10;
        p = (p + ans[i]) / 10;
        ans[i] = ost;
    }
    while (ans.back() == 0)
        ans.pop_back();
    string u = "";
    while (!ans.empty())
    {
        u += (char)('0' + ans.back());
        ans.pop_back();
    }
    return u;
}

int n;
string s;

string gett(int i)
{
    string s1 = "";
    for (int x = 0; x < i; x++)
        s1 += s[x];
    string s2 = "";
    for (int x = i; x < n; x++)
        s2 += s[x];
    return sum(s1, s2);
}

bool cmp(string a, string b)
{
    if ((int)a.size() != (int)b.size())
        return (int)a.size() < (int)b.size();
    return (a < b);
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    vector<int> cand;
    int k = 0;
    for (int i = n / 2; i < n && k < 3; i++)
        if (s[i] != '0')
        {
            cand.push_back(i);
            k++;
        }
    k = 0;
    for (int i = n / 2; i >= 1 && k < 3; i--)
        if (s[i] != '0')
        {
            cand.push_back(i);
            k++;
        }
    vector<string> v;
    for (int i : cand)
        v.push_back(gett(i));
    sort(v.begin(), v.end(), cmp);
    cout << v[0];
    return 0;
}