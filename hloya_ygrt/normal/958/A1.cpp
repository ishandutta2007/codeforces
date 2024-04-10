// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 


#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mt make_tuple
#define f first
#define s second

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { if (b < a) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = (int)2e9;
const int maxn = 5e5 + 5, inf = 2e9;

int n;
vector<string> rot(vector<string> a) {
    auto ans = a;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[n - j - 1][i] = a[i][j];
    return ans;
}

vector<string> fl1(vector<string> a) {
    auto ans = a;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][n - j - 1] = a[i][j];
    return ans;
}

vector<string> fl2(vector<string> a) {
    auto ans = a;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[n - i - 1][j] = a[i][j];
    return ans;
}


int main() {
    srand(time(0));

    // freopen("input.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    cin >> n;

    vector<string> a, b;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.pb(s);
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        b.pb(s);
    }

    set<vector<string> > used;
    queue<vector<string> > q;

    q.push(a);

    while (!q.empty()) {
        auto e = q.front();
        q.pop();

        if (e == b) {
            puts("Yes");
            return 0;
        }

        if (used.count(e)) continue;
        used.insert(e);

        auto u = rot(e);
        q.push(u);

        auto v = fl1(e);
        q.push(v);

        auto w = fl2(e);
        q.push(w);
    }
    puts("No");
    return 0;
}