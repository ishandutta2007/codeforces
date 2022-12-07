#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<functional>
#ifdef LOCAL
#include "template.h"
#endif

using namespace std;
#ifndef LOCAL
#define dbg(...) (void)0
#define ARR(arr, ...) (void)0
#define eprintf(...) (void)0
#endif

#define mp make_pair
#define rand govno_ebanoe
#define dbg_time() eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC)

using ll = long long;
using pii = pair<int, int>;
using dbl = double;

struct Friend {
    int x, y;
    Friend() = default;
    Friend(int _x, int _y) : x(_x), y(_y) {}

    static Friend read() {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        return {x, y};
    }
};

pair< bool, vector<int> > order_friends(vector<int> plates, const vector<Friend>& friends) {
    vector< vector<int> > eaters(plates.size());
    for(size_t i = 0; i < friends.size(); ++i) {
        const auto& f = friends[i];
        --plates[f.x];
        eaters[f.x].push_back(i);
        --plates[f.y];
        eaters[f.y].push_back(i);
    }
    vector<int> order;
    vector<int> eaten;
    vector<bool> used(friends.size(), false);
    for(size_t i = 0; i < plates.size(); ++i)
        if (plates[i] >= 0)
            eaten.push_back(i);
    for(size_t i = 0; i < eaten.size(); ++i) {
        auto pid = eaten[i];
        for(auto ead : eaters[pid]) {
            if (used[ead])
                continue;
            used[ead] = true;
            order.push_back(ead);
            const auto& f = friends[ead];
            ++plates[f.x];
            if (plates[f.x] == 0)
                eaten.push_back(f.x);
            ++plates[f.y];
            if (plates[f.y] == 0)
                eaten.push_back(f.y);
        }
    }
    if (eaten.size() != plates.size()) {
        return {false, {}};
    }
    // assert all used are true
    reverse(order.begin(), order.end());
    return {true, order};
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> plates(n);
    for(auto& p : plates)
        scanf("%d", &p);
    vector<Friend> friends;
    friends.reserve(m);
    for(int i = 0; i < m; ++i)
        friends.push_back(Friend::read());
    bool alive;
    vector<int> order;
    tie(alive, order) = order_friends(plates, friends);
    if (alive) {
        puts("ALIVE");
        for(auto x : order)
            printf("%d ", x + 1);
        puts("");
        return;
    } 
    puts("DEAD");
}

int main() {
#ifndef LOCAL
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

		int test_count = 1;
#ifdef MULTITEST
		scanf("%d", &test_count);
		char endl1[5];
		fgets(endl1, 5, stdin);
#endif
		for (int i = 0; i < test_count; ++i) {
#ifdef CASES
			printf("Case #%d: ", i + 1);
			solve();
			eprintf("Passed case #%d:\n", i + 1);
#else
			solve();
#endif
		}
	dbg_time();
    return 0;
}