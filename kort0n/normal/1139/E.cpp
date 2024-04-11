#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
template< typename flow>
struct max_flow {
    struct edge {
        int to;
        flow cap;
        int rev; };
    int V;
    vector<vector<edge>> G;
    vector<int> itr, level;

    max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

    void add_edge(int from, int to, flow cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V,-1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    flow dfs(int v, int t, flow f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                flow d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow run(int s, int t) {
        flow ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V,0);
            while ((f = dfs(s, t, INF)) > 0) ret += f;
        }
        return ret;
    }
};
int ans[5005];
int p[5005];
int c[5005];
int n, m;
int d;
int k[5005];
bool isdeleted[5005];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    cin >> d;
    for(int i = 1; i <= d; i++) {
        cin >> k[i];
        isdeleted[k[i]] = true;
    }
    max_flow<int> field(15010);
    for(int group = 1; group <= m; group++) field.add_edge(0, group, 1);
    for(int student = 1; student <= n; student++) {
        if(isdeleted[student]) continue;
        cerr << student << endl;
        field.add_edge(c[student], m + student, 1);
        field.add_edge(m + student, 10001 + p[student], 1);
    }
    ans[d+1] = 0;
    field.add_edge(10001+0, 15009, 1);
    for(int day = d; day >= 1; day--) {
        //int ok = ans[day+1];
        //int ng = n+1;
        ans[day] = ans[day+1];
        while(ans[day] != n) {
            if(field.run(0, 15009) == 0) break;
            ans[day]++;
            field.add_edge(10001+ans[day], 15009, 1);
        }
        int student = k[day];
        field.add_edge(c[student], m + student, 1);
        field.add_edge(m + student, 10001 + p[student], 1);
        //ans[day] = ok;
        //cout << ok << endl;
    }
    for(int i = 1; i <= d; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}