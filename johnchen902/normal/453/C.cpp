#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> adj[100000];
bool x[100000];
bool v[100000];
vector<int> ans;
void visit(int i) {
    ans.push_back(i);
    x[i] = !x[i];
    v[i] = true;
}
void dfs(int i) {
    visit(i);
    for(int j : adj[i])
        if(!v[j]) {
            dfs(j);
            visit(i);
            if(x[j]) {
                visit(j);
                visit(i);
            }
        }
}
void solve() {
    for(int i = 0; i < n; i++)
        if(x[i]) {
            dfs(i);
            if(x[i]) {
                ans.pop_back();
                x[i] = 0;
            }
            break;
        }
}
int main(){
    int m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int p, q;
        scanf("%d %d", &p, &q);
        p--;
        q--;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    for(int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        x[i] = p;
    }
    solve();
    if(count(x, x + n, 1) != 0) {
        puts("-1");
    } else {
        printf("%d\n", (int) ans.size());
        for(int i = 0; i < (int) ans.size(); i++)
            printf("%d%c", ans[i] + 1, (i == (int) ans.size() - 1) ? '\n' : ' ');
    }
}