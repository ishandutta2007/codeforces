#include <bits/stdc++.h>
using namespace std;

enum TYPE {
    AND, IN, XOR, NOT, OR
};

struct S
{
    TYPE t;
    int first, second;
    int initial;
    int res;
};

vector<S> v;

int dfs2(int cur) {
    auto& c = v[cur];
    if (c.t == IN)
        return c.initial = c.first;
    if (c.t == NOT)
        return c.initial = !dfs2(c.first);
    if (c.t == AND)
        return c.initial = dfs2(c.first) & dfs2(c.second);
    if (c.t == OR)
        return c.initial = dfs2(c.first) | dfs2(c.second);
    if (c.t == XOR)
        return c.initial = dfs2(c.first) ^ dfs2(c.second);
    return -1;
}

void dfs(int cur, int YES, int NO) {
    auto& c = v[cur];
    if (c.t == IN) {
        if (c.first == 1)
            c.res = NO;
        else
            c.res = YES;
    }
    if (c.t == NOT) {
        dfs(c.first, NO, YES);
    }
    auto x = c.first;
    auto y = c.second;
    array<int, 2> arr{NO, YES};
    if (c.t == AND) {
        dfs(x, arr[v[y].initial], NO);
        dfs(y, arr[v[x].initial], NO);
    }
    if (c.t == OR) {
        dfs(x, YES, arr[v[y].initial]);
        dfs(y, YES, arr[v[x].initial]);
    }
    if (c.t == XOR) {
        dfs(x, arr[!v[y].initial], arr[v[y].initial]);
        dfs(y, arr[!v[x].initial], arr[v[x].initial]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        auto& t = v[i].t;
        if (s == "IN")
            t = IN;
        if (s == "AND")
            t = AND;
        if (s == "NOT")
            t = NOT;
        if (s == "OR")
            t = OR;
        if (s == "XOR")
            t = XOR;
        cin >> v[i].first;
        if (t != IN)
            v[i].first--;
        if (t == AND || t == OR || t == XOR) {
            cin >> v[i].second;
            v[i].second--;
        }
    }

    dfs2(0);
    dfs(0, 1, 0);
    for (auto c : v) {
        if (c.t == IN)
            cout << c.res;
    }
    cout << endl;
}