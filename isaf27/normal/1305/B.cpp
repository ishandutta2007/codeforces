//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

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
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1e4 + 239;

string s;
int n;

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = (int)s.size();
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            v1.push_back(i);
        else
            v2.push_back(i);
    }
    reverse(v2.begin(), v2.end());
    vector<int> a1, a2;
    int i = 0;
    int j = 0;
    while (i < v1.size() && j != v2.size())
    {
        if (v1[i] >= v2[j])
            break;
        a1.push_back(v1[i]);
        a2.push_back(v2[j]);
        i++;
        j++;
    }
    if (a1.empty())
    {
        cout << "0\n";
        return 0;
    }
    cout << "1\n";
    cout << 2 * (int)a1.size() << "\n";
    for (int i : a1)
        cout << i + 1 << " ";
    reverse(a2.begin(), a2.end());
    for (int i : a2)
        cout << i + 1 << " ";
    cout << "\n";
    return 0;
}