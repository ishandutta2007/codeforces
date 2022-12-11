#include <iostream>
#include <vector>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

int n;
vector<int> c;

vector<int> greedy(int val, int pos)
{
    vector<int> g(n);
    while (val) {
        g[pos] = val / c[pos];
        val -= g[pos] * c[pos];
        ++pos;
    }
    return g;
}

int greedy_cnt(int val)
{
    int ans = 0;
    int pos = 0;
    while (val) {
        int g = val / c[pos];
        val -= g * c[pos];
        ans += g;
        ++pos;
    }
    return ans;
}

const int inf = 2e9 + 100;

int main()
{

    cin >> n;
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    int ans = inf;

    for (int i = n - 1; i; --i) {
        vector<int> g = greedy(c[i - 1] - 1, i);
        int val0 = 0, cnt_m0 = 0;
        for (int k = 0; k < i; ++k) {
            val0 += c[k] * g[k];
            cnt_m0 += g[k];
        }
        for (int j = i; j < n; ++j) {
            int val = val0 + c[j] * (g[j] + 1);
            int cnt_m = cnt_m0 + g[j] + 1;
            int cnt_g = greedy_cnt(val);
            if (cnt_m < cnt_g) {
                ans = min(ans, val);
            }
            val0 += c[j] * g[j];
            cnt_m0 += g[j];
        }
    }

    cout << (ans == inf ? -1 : ans) << "\n";

}