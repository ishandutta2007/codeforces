#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 150005;
const ll inf = 1e18;

ll ans[2][maxn];
deque<pair<ll, int> > st;
int n, m, d;

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n; i++) ans[0][i] = 0;
    int lastt = 0;
    for (int IT = 0; IT < m; IT++)
    {
        int wh, B, T;
        scanf("%d%d%d", &wh, &B, &T);
        wh--;
        ll len = (ll)d * (T - lastt);
        lastt = T;
        while (!st.empty()) st.pop_front();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.back().first < ans[IT & 1][i]) st.pop_back();
            st.push_back(make_pair(ans[IT & 1][i], i));
            while (!st.empty() && st.front().second + len < i) st.pop_front();
            ans[(IT + 1) & 1][i] = st.front().first;
        }
        while (!st.empty()) st.pop_front();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.back().first < ans[IT & 1][i]) st.pop_back();
            st.push_back(make_pair(ans[IT & 1][i], i));
            while (!st.empty() && st.front().second - len > i) st.pop_front();
            ans[(IT + 1) & 1][i] = max(ans[(IT + 1) & 1][i], st.front().first);
        }
        for (int i = 0; i < n; i++) ans[(IT + 1) & 1][i] += B - abs(i - wh);
    }
    ll answer = -inf;
    for (int i = 0; i < n; i++) answer = max(answer, ans[m & 1][i]);
    cout << answer << endl;
	return 0;
}