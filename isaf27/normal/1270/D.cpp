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
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 19;
const int T = (1 << 20);
const int B = 500;
const int X = 1e4 + 239;

pair<int, int> ask(vector<int> v)
{
    cout << "? ";
    for (int i : v)
        cout << i + 1 << " ";
    cout << endl;
    int p, val;
    cin >> p >> val;
    p--;
    return make_pair(p, val);
}

void answer(int m)
{
    cout << "! " << m << endl;
    exit(0);
}

int32_t main()
{
#ifdef ONPC
    //freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> al;
    vector<int> id;
    for (int i = 0; i < k; i++)
        id.push_back(i);
    for (int i = k; i <= n; i++)
    {
        pair<int, int> t = ask(id);
        for (int p = 0; p < k; p++)
            if (id[p] == t.first)
            {
                swap(id[p], id.back());
                break;
            }
        id.pop_back();
        al.push_back(make_pair(t.second, t.first));
        if (i != n)
            id.push_back(i);
    }
    sort(al.begin(), al.end());
    int pm = al[0].second;
    int px = al[1].second;
    int m = 1;
    for (int i : id)
    {
        vector<int> now = {pm, px};
        for (int t : id)
            if (t != i)
                now.push_back(t);
        pair<int, int> cur = ask(now);
        if (cur.first == px)
            m++;
    }
    answer(m);
    return 0;
}