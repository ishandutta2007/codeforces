#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 3e5 + 500, base = 1e9+7;

struct edge
{
    int f, t, is_art;
    edge(int f,int t,int is_art):f(f),t(t),is_art(is_art){}
};

set<pair<int,int> > brg, sot;
vector<edge> input;
vector<int> g[maxn];

int tin[maxn], fup[maxn];
bool used[maxn];
int timer = 0;

void dfs(int v,int p = -1)
{
    used[v] = 1;
    tin[v] = fup[v] = ++timer;
    for (int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if (p != to){
            if (used[to])
                fup[v] = min(fup[v], tin[to]);
            else
            {
                dfs(to, v);
                fup[v] = min(fup[v], fup[to]);
                if (fup[to] > tin[v])
                    brg.insert(mp(v,to)), brg.insert(mp(to,v));
            }
        }
    }
}

void find_brg(int n)
{
    for (int i=0; i < n;i++){
        if (!used[i])
            dfs(i);
    }
}

int parent[maxn], _rank[maxn];

void make_set(int v)
{
    parent[v] = v;
    _rank[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) {

        if (_rank[a] < _rank[b])
            swap(a, b);
        parent[b]  = a;
        if (_rank[a] == _rank[b])
            _rank[a] ++;

    }
}

int art[maxn];

    int a, b;
vector<pair<int,int> > vis;

void answer()
{
    for (int i=0;i<vis.size();i++){
      // cout << vis[i].f << ' ' << vis[i].s << endl;
        int foo = vis[i].f, bar = vis[i].s;
        if (brg.find(mp(foo, bar)) != brg.end()){
            if (sot.count(mp(foo, bar)) || sot.count(mp(bar, foo))){
                puts("YES");
                return;
            }
        } 
        if (art[find_set(foo)] || art[find_set(bar)]){
               puts("YES");
               return;    
        }
        
    }
    puts("NO");
}
void Try(int v)
{
    if (v == b){
        answer();
        exit(0);
    }
    used[v] = 1;
    for (int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if (!used[to]){
            vis.pb(mp(v,to));
            Try(to);
            vis.pop_back();
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<m;i++){
        int foo, bar, is_art;
        scanf("%d %d %d", &foo, &bar, &is_art);
        foo--, bar--;
        g[foo].pb(bar);
        g[bar].pb(foo);

        input.pb(edge(foo,bar,is_art));
    }

    find_brg(n);

    for (int i=0;i<n;i++)
        make_set(i);

    for (int i=0;i<m;i++){
        int foo, bar;
        foo = input[i].f, bar = input[i].t;
        if (brg.find(mp(foo, bar)) == brg.end()){
            union_sets(foo, bar);
        }
    }

    for (int i=0;i<m;i++){
        int foo, bar, is_art;
        foo = input[i].f, bar = input[i].t, is_art = input[i].is_art;
        if (is_art){
            if (brg.find(mp(foo, bar)) == brg.end()){
                art[find_set(foo)]++;
            } else {
                sot.insert(mp((foo), (bar)));
            }
        }
    }

    scanf("%d %d", &a, &b);
    a--, b--;

    if (find_set(a) == find_set(b)){
        if (art[find_set(a)] != 0){
            puts("YES");
        } else {
            puts("NO");
        }
    } else {
        memset(used, 0, sizeof(used));
        Try(a);
    }
    return 0;
}