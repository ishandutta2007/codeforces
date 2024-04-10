#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define lock lockkk

const int N = 1e6 + 20;
const int INF = 1e9 + 19;

int n;
long long w[N];
int use[N];
int tmr;
int lock[N];
int dist[N];
int p[N];
vector < pair < int, int > > e[N];
queue < int > q;
double answer = 1e50;
int sert = -1;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &w[i]); 

    for (int i = 0; i < n - 1; i++) {
        int v, u, cost;
        scanf("%d%d%d", &v, &u, &cost);
        v--;
        u--;
        e[v].pb(mp(u, cost));
        e[u].pb(mp(v, cost));
    }
}

double dfs1(int v, int h) {
    use[v] = tmr;
    double res = w[v] * sqrt(h + 0.0) * h;
    for (auto x: e[v]) {
        if (use[x.fr] != tmr) {
            res += dfs1(x.fr, h + x.sc);
        }
    }
    return res;
}

double calc(int v) {
    tmr++;
    double res = dfs1(v, 0); 
    if (res < answer) {
        answer = res;
        sert = v;
    }
    return res;
}

int bfs(int v) {
    memset(dist, 63, sizeof(dist));
    q.push(v);
    dist[v] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto x: e[v])
            if (dist[x.fr] > dist[v] + 1 && !lock[x.fr]) {
                dist[x.fr] = dist[v] + 1;
                p[x.fr] = v;
                q.push(x.fr);
            }
    }
    return v;
}


void solve() {
    int curV = 0; 
    for (;;) {
        int st = bfs(curV);      
        int fn = bfs(st);
        vector < int > path; 
        int v = fn;
        for (;v != st;) {
            path.pb(v);
            v = p[v];
        }
        path.pb(st);

        if (dist[fn] > 2) {
            
            int mid1 = path[(path.size() - 1) / 2];
            int mid2 = path[(path.size() - 1) / 2 + 1];
            double r1 = calc(mid1);
            double r2 = calc(mid2);
            if (r1 > r2) {
                lock[mid1] = 1;
                curV = mid2;
            }
            else {
                lock[mid2] = 1;
                curV = mid1;
            }
        }
        else {
            int mid = path[path.size() / 2];
            calc(mid); 
            calc(curV);
            int best = 0;
             
            for (int i = 0; i < (int)e[mid].size(); i++)
                if (w[e[mid][i].fr] > w[e[mid][best].fr]) {
                    best = i;
                }
            if (!e[mid].empty()) 
                calc(e[mid][best].fr);

            random_shuffle(e[mid].begin(), e[mid].end());
            for (auto x: e[mid]) {
                if (clock() * 1.0 / CLOCKS_PER_SEC > 1.7) break;
                calc(x.fr);
            }

            break;
        }
    }

    printf("%d %.17f\n", sert + 1, answer); 



}

void stress() {

}


int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    if (1) {
        int k = 1;         
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }



    return 0;
}