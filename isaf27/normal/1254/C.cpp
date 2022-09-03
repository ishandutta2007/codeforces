//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
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
const int MOD = 998244353; // (int)(1e9 + 7);
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 20);
const int B = 500;
const int X = 1e6 + 239;

ll getsqr(int i, int j, int k)
{
    cout << "1 " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    ll ans;
    cin >> ans;
    return ans;
}

int getsign(int i, int j, int k)
{
    cout << "2 " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

void over(vector<int> p)
{
    cout << "0 ";
    for (int i : p)
        cout << i + 1 << " ";
    cout << endl;
    exit(0);
}

int32_t main()
{
#ifdef ONPC
    //freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int id = 1;
    for (int i = 2; i < n; i++)
    {
        int s = getsign(0, id, i);
        if (s == -1)
            id = i;
    }
    vector<pair<ll, int>> s;
    for (int i = 0; i < n; i++)
        if (i != 0 && i != id)
            s.push_back(make_pair(getsqr(0, id, i), i));
    sort(s.begin(), s.end());
    int p = s.back().second;
    vector<int> vl, vr;
    for (pair<ll, int> t : s)
        if (t.second != p)
        {
            if (getsign(0, t.second, p) == 1)
                vl.push_back(t.second);
            else
                vr.push_back(t.second);
        }
    vector<int> ans;
    ans.push_back(0);
    ans.push_back(id);
    for (int i : vl)
        ans.push_back(i);
    ans.push_back(p);
    reverse(vr.begin(), vr.end());
    for (int i : vr)
        ans.push_back(i);
    over(ans);
    return 0;
}