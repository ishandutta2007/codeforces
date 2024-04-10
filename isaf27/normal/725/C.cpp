#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 19);
const int B = (int)(trunc(sqrt(M)) + 1);
const int X = 1e4 + 239;

int main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n = 27;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i] == s[j])
            {
                if (j == i + 1)
                {
                    cout << "Impossible";
                    return 0;
                }
                string s1 = "";
                for (int x = i + 1; x < j; x++)
                    s1 += s[x];
                string s2 = "";
                for (int x = (j + 1) % n; x != i; x = (x + 1) % n)
                    s2 += s[x];
                vector<string> ans(2);
                for (int d = 0; d < 2; d++)
                    for (int x = 0; x < 13; x++)
                        ans[d] += " ";
                int num = (int)s1.size() + 1;
                int p = (num + 1) / 2;
                p--;
                ans[0][p] = s[i];
                int l = p;
                for (int x = p - 1; x >= 0; x--)
                    ans[0][x] = s1[p - 1 - x];
                for (int x = 0; x < (int)s1.size() - p; x++)
                    ans[1][x] = s1[p + x];
                p = (int)s1.size() - p;
                for (int x = p; x < 13; x++)
                    ans[1][x] = s2[x - p];
                for (int x = 12; x > l; x--)
                    ans[0][x] = s2[(int)s2.size() + l - x];
                cout << ans[0] << "\n" << ans[1] << "\n";
                return 0;
            }
    return 0;
}