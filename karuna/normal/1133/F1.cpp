#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

queue<pii> q;
vector<vector<int> > v;
bool visited[202020];
vector<pii> e;
void bfs(int k){
    visited[k] = true;

    int sz = v[k].size();
    for (int i=0; i<sz; i++) {
        q.push(make_pair(v[k].at(i), k));
    }

    pii temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (visited[temp.first] == false) {
            e.push_back(temp);
            bfs(temp.first);
        }
    }
    return;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    v.resize(n);
    int a, b;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    int maxi = 0, max_v = 0;
    for (int i=0; i<n; i++) {
        int k = v[i].size();
        if (maxi < k) {
            maxi = k;
            max_v = i;
        }
    }

    bfs(max_v);

    int sz = e.size();
    for (int i=0; i<sz; i++) {
        printf("%d %d\n", e[i].first+1, e[i].second+1);
    }
}