#include <bits/stdc++.h>
using namespace std;
const int N = 5111;

vector<int> adj[N];
bool reach[N][N];
int rep[N], ins[N];
int main() {
    int n, e, s;
    scanf("%d%d%d", &n, &e, &s);
    while (e--) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[--a].push_back(--b);
    }
    for (int p = 0; p < n; p++) {
        bool *vis = reach[p];
        vis[p] = true;
        stack<int> st;
        st.push(p);
        while (!st.empty()) {
            int i = st.top(); st.pop();
            for (int j : adj[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    st.push(j);
                }
            }
        }
        while (!(reach[p][rep[p]] && reach[rep[p]][p])) rep[p]++;
        ins[p] = p != rep[p];
    }
    ins[rep[--s]] = 1;
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            if (rep[i] != rep[j]) ins[rep[j]] = 1;
        }
    }
    printf("%d\n", n - accumulate(ins, ins + n, 0));
}