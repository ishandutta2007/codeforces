#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;

struct op {
    char c;
    int x, y;
    void scan(int i) {
        static char in[10];
        cin >> in >> x;
        if (*in == 'A' || *in == 'O' || *in == 'X') cin >> y;
        c = *in;
    }
} ops[1000001];
int res[1000001];
int ch[1000001];

void dfs(int x) {
    char c = ops[x].c;
    if (c == 'I') {
        res[x] = ops[x].x;
        return;
    }
    if (c == 'A') {
        dfs(ops[x].x);
        dfs(ops[x].y);
        res[x] = (res[ops[x].x] & res[ops[x].y]);
    }
    if (c == 'O') {
        dfs(ops[x].x);
        dfs(ops[x].y);
        res[x] = (res[ops[x].x] | res[ops[x].y]);
        
    }
    if (c == 'X') {
        dfs(ops[x].x);
        dfs(ops[x].y);
        res[x] = (res[ops[x].x] ^ res[ops[x].y]);
        
    }
    if (c == 'N') {
        dfs(ops[x].x);
        res[x] = (res[ops[x].x] ^ 1);
    }
}

void dfs2(int x) {
    char c = ops[x].c;
    int a = ops[x].x;
    int b = ops[x].y;
    if (c == 'I') {
        ch[x] = 1;
        return;
    }
    if (c == 'A') {
        if (res[a] + res[b] == 0) return;
        if (res[a] == 0) dfs2(a);
        if (res[b] == 0) dfs2(b);
        if (res[a] && res[b]) dfs2(a), dfs2(b);
    }
    if (c == 'O') {
        if (res[a] && res[b]) return;
        if (res[a]) dfs2(a);
        if (res[b]) dfs2(b);
        if (res[a] + res[b] == 0) dfs2(a), dfs2(b);
    }
    if (c == 'X') {
        dfs2(a);
        dfs2(b);
    }
    if (c == 'N') {
        dfs2(a);
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
        ops[i].scan(i);
	}
	dfs(1);
	dfs2(1);
	for (int i = 1; i <= n; ++i) {
        if (ops[i].c == 'I') {
            printf("%d", res[1] ^ ch[i]);
        }
	}
	return 0;
}