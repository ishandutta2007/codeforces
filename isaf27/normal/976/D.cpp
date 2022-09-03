//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)

mt19937 rnd(239);

const ld pi = acos(-1.0);
const ll INF = 1e18 + 239;
const int BIG = 1e9 + 239;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int X = 1e4 + 239;
const int L = 18;
const int T = (1 << 19);
const int two = 2;
const int th = 3;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<pair<int, int> > ans;

void gen(vector<int> d)
{
    if (d.size() == 1)
    {
        for (int i = 0; i <= d[0]; i++)
            for (int j = i + 1; j <= d[0]; j++)
                ans.push_back(make_pair(i, j));
        return;
    }
    if (d.size() == 2)
    {
        for (int i = 0; i < d[0]; i++)
            for (int j = i + 1; j <= d[1]; j++)
                ans.push_back(make_pair(i, j));
        return;
    }
    int n = d.size();
    for (int j = d[n - 1]; j >= d[n - 1] - d[0] + 1; j--)
        for (int i = j - 1; i >= 0; i--)
            ans.push_back(make_pair(i, j));
    vector<int> nw;
    for (int i = 1; i < n - 1; i++)
        nw.push_back(d[i] - d[0]);
    gen(nw);
}

int main()
{   //*
	#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout); 
    #endif /**/
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
    vector<int> d;
    cin >> n;
    d.resize(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    gen(d);
    cout << ans.size() << "\n";
    for (pair<int, int> t : ans)
        cout << t.first + 1 << " " << t.second + 1 << "\n";
    return 0;
}