#include <bits/stdc++.h>
using namespace std;
const int N = 1000111;

vector<int> adj[N];
vector<int> *arr[N];
int parent[N], best[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        arr[i] = new vector<int>;
        parent[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> que(1, 0);
    parent[0] = 0;
    for (int f = 0; f < que.size(); f++) {
        int i = que[f];
        for (int j : adj[i]) {
            if (!~parent[j]) {
                parent[j] = i;
                que.push_back(j);
            }
        }
    }
    reverse(que.begin(), que.end());
    for (int i : que) {
        arr[i]->push_back(1);
        best[i] = 0;
        for (int j : adj[i]) {
            if (j == parent[i]) continue;
            arr[j]->push_back(0);
            if (arr[i]->size() < arr[j]->size()) {
                swap(arr[i], arr[j]);
                best[i] = best[j] + 1;
            }
            for (int k = arr[j]->size(); k--;) {
                (*arr[i])[arr[i]->size()-1-k] += (*arr[j])[arr[j]->size()-1-k];
                if ((*arr[i])[arr[i]->size()-1-best[i]] <= (*arr[i])[arr[i]->size()-1-k]) {
                    best[i] = k;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", best[i]);
    }
}