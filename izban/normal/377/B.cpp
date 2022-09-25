#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, s;
pair<int, int> a[maxn];
pair<pair<int, int>, int> b[maxn];

bool f(int x, bool need) {
    int i = m - 1;
    
    int cr = n - 1;
    set<pair<int, int> > st;
    vector<int> ans(m, -1);
    int cost = 0;
    while (i >= 0) {
        while (cr >= 0 && b[cr].first.first >= a[i].first) {
            st.insert(make_pair(b[cr].first.second, cr));
            cr--;
        }
        if (st.empty()) return 0;
        int o = st.begin()->second;
        cost += b[o].first.second;
        if (cost > s) return 0;
        st.erase(st.begin());
        for (int j = 0; j < x && i >= 0; j++, i--) {
            ans[a[i].second] = b[o].second + 1;
        }
    }
    if (need) {
        cout << "YES" << endl;
        for (int i = 0; i < m; i++) cout << ans[i] << " \n"[i == m - 1];
    }
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int test = 0;
    while (cin >> n >> m >> s) {
        //cerr << ++test << endl;
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i].first.first);
            b[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i].first.second);
        }
        sort(a, a + m);
        sort(b, b + n);
        
        int l = 1, r = 1e5;
        while (r - l > 1) {
            ll M = (l + r) >> 1;
            if (f(M, 0)) r = M;
            else l = M;
        }
        if (!f(l, 1)) if (!f(r, 1)) cout << "NO" << endl;
    }

	return 0;
}