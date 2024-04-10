#include <cstdio>
#include <unordered_map>
#include <stack>
#include <vector>
#include <utility>
using namespace std;
vector<int> factorize(int x) {
    vector<int> v;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            v.push_back(i);
            do { x /= i; } while(x % i == 0);
        }
    }
    if(x > 1) v.push_back(x);
    return move(v);
}

int n;
vector<int> st;
unordered_map<int, stack<int>> mp;
int a[100000];
vector<int> fac[100000];
vector<int> adj[100000];
int ans[100000];

int top(int x) {
    if(!mp.count(x) || mp[x].empty()) return -1;
    return mp[x].top();
}

void dfs(int x = 0, int p = -1) {
    int maxi = -1;
    for(int i : fac[x])
        maxi = max(maxi, top(i));
    ans[x] = maxi == -1 ? -1 : st[maxi];

    st.push_back(x);
    for(int i : fac[x])
        mp[i].push(st.size() - 1);

    for(int i : adj[x])
        if(i != p)
            dfs(i, x);

    st.pop_back();
    for(int i : fac[x])
        mp[i].pop();
}

int main(){
    int q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
        fac[i] = factorize(a[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs();
    while(q--) {
        int cmd;
        scanf("%d", &cmd);
        if(cmd == 1) {
            int v;
            scanf("%d", &v);
            v--;
            printf("%d\n", ans[v] == -1 ? -1 : ans[v] + 1);
        } else {
            int v, w;
            scanf("%d %d", &v, &w);
            v--;
            a[v] = w;
            fac[v] = factorize(w);
            dfs();
        }
    }
}