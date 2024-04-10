#include <bits/stdc++.h>

using namespace std;

const int M = 5005;
const int P = 998244353;

int N, V;

string S;

vector<int> adj[M];
vector<int> parity;

void add_edge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void equal(int a, int b) {
    add_edge(a, V);
    add_edge(b, V);
    ++V;
}

bool dfs(int node, int p) {
    parity[node] = p;
    for (int neighbor : adj[node]) {
        if (parity[neighbor] == p) return false;
        if (parity[neighbor] < 0) {
            if (!dfs(neighbor, 1 - p)) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    N = S.size();
    if (S.back() == '1') {
        cout << 0 << '\n';
        return 0;
    }
    long long total = 0;
    for (int length = 1; length < N; length++) {
        for (int i = 0; i < M; i++) adj[i].clear();
        V = N + length + 2;
        int zero = V - 2, one = V - 1;
        add_edge(zero, one);
        equal(0, one);
        equal(N - 1, one);
        equal(N, one);
        equal(N + length - 1, one);
        for (int i = 1; i < N - length; i++)
            if (S[i] != '?') equal(i, S[i] == '0' ? zero : one);
        for (int i = N - length; i < N; i++)
            if (S[i] == '0')
                equal(i, i + length);
            else if (S[i] == '1')
                add_edge(i, i + length);
        for (int i = 0, j = N - 1; i < j; i++, j--) equal(i, j);
        for (int i = 0, j = length - 1; i < j; i++, j--) equal(N + i, N + j);
        parity.assign(V, -1);
        bool valid = dfs(zero, 0);
        int components = 0;
        for (int i = 0; i < V; i++)
            if (parity[i] < 0) {
                components++;
                valid = valid && dfs(i, 0);
            }
        if (!valid) continue;
        long long now = 1;
        for (int i = 0; i < components; i++) now = 2 * now % P;
        total = (total + now) % P;
    }
    cout << total << '\n';
    return 0;
}