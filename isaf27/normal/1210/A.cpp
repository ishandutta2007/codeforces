//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0

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
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = 500;
const int X = 10;

int n, m, ans;
vector<pair<int, int>> rb;

vector<int> v;

void gen(int b)
{
    if (b == n)
    {
        vector<pair<int, int>> al;
        for (pair<int, int> t : rb)
        {
            int s = v[t.first];
            int f = v[t.second];
            if (s > f)
                swap(s, f);
            al.push_back(make_pair(s, f));
        }
        sort(al.begin(), al.end());
        al.resize(unique(al.begin(), al.end()) - al.begin());
        ans = max(ans, (int)al.size());
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        v.push_back(i);
        gen(b + 1);
        v.pop_back();
    }
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        rb.push_back(make_pair(s, f));
    }
    gen(0);
    cout << ans;
    return 0;
}