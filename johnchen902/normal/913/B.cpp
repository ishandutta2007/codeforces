#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> adj[1000];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        x--;
        adj[x].push_back(i);
    }
    if (all_of(adj, adj + n,
        [](const vector<int> &v) {
            if (v.empty())
                return true;
            int cnt = 0;
            for (int c : v)
                if (adj[c].empty())
                    cnt++;
            return cnt >= 3;
        })) {
        puts("Yes");
    } else {
        puts("No");
    }
}