#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct data
{
    int x, y;
    int len;
    int cost;
    data() : x(-1), y(-1), len(0) {}
};

vector<data> d;
vector<vector<int> > g;

void relax(int v, int x, int y, int l)
{
    if (d[v].x <= d[v].y && x > y) {
        d[v].x = x, d[v].y = y;
        d[v].len = l;
        return;
    }
    if (d[v].x > d[v].y && x <= y) {
        return;
    }
    /*if (d[v].x <= d[v].y && d[v].y - d[v].x > y - x) {
        d[v].x = x, d[v].y = y;
        return;
    }*/
    if (d[v].x < x) {
        d[v].x = x, d[v].y = y;
        d[v].len = l;
        return;
    }
    if (d[v].x > x) {
        return;
    }
    if (d[v].y > y) {
        d[v].len = l;
        d[v].y = y;
    }
}

void dfs(int v)
{
    if (d[v].x != -1) {
        return;
    }
    d[v].x = d[v].y = 0;
    for (int to : g[v]) {
        dfs(to);
    }
    for (int to : g[v]) {
        int xx = d[to].cost + d[to].y;
        int yy = d[to].x;
        if (d[v].x == 0 && d[v].y == 0) {
            d[v].x = xx, d[v].y = yy, d[v].len = d[to].len + 1;
        } else {
            relax(v, xx, yy, d[to].len + 1);
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    map<string, int> cnt;
    cnt[""] = n;

    for (int i = 0; i < n; ++i) {
        set<string> st;
        for (int j = 0; j < sz(v[i]); ++j) {
            string s = "";
            for (int len = 1; j + len - 1 < sz(v[i]); ++len) {
                s += v[i][j + len - 1];
                if (!st.count(s)) {
                    st.insert(s);
                    ++cnt[s];
                }
            }
        }
    }

    map<string, int> id;
    for (auto it : cnt) {
        data tmp;
        tmp.cost = 0;
        int maxx = 0;
        for (int i = 0; i < sz(it.first); ++i) {
            tmp.cost += it.first[i] - 'a' + 1;
            maxx = max(maxx, it.first[i] - 'a' + 1);
        }
        tmp.cost *= maxx;
        tmp.cost += it.second;
        id[it.first] = sz(d);
        d.pb(tmp);
    }

    int s = sz(d);
    g.resize(s);

    for (auto it : id) {
        string t = it.first;
        for (char c = 'a'; c <= 'z'; ++c) {
            string str = "";
            str += c;
            str += t;
            if (id.count(str)) {
                g[it.second].pb(id[str]);
            }
            str = t;
            str += c;
            if (id.count(str)) {
                g[it.second].pb(id[str]);
            }
        }
    }

    dfs(id[""]);
    int x = d[id[""]].x;
    int y = d[id[""]].y;
    int l = d[id[""]].len;

    if (l & 1) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
    cout << x << " " << y << "\n";

}