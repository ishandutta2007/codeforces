#include <bits/stdc++.h>

using namespace std;

const int N = 300000;
const int M = N << 2;
const int INF = 1000000000;

int where[N];
int tree[M], lazy[M];

void build(int node, int left, int right) {
    lazy[node] = 0;
    if (left == right) {
        tree[node] = -INF;
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

void push(int node) {
    tree[2 * node] += lazy[node];
    tree[2 * node + 1] += lazy[node];
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
}

void update(int node, int left, int right, int from, int to, int value) {
    if (from <= left && right <= to) {
        lazy[node] += value;
        tree[node] += value;
        return;
    }
    int middle = (left + right) / 2;
    push(node);
    if (from <= middle)
        update(2 * node, left, middle, from, to, value);
    if (middle + 1 <= to)
        update(2 * node + 1, middle + 1, right, from, to, value);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to)
        return tree[node];
    push(node);
    int middle = (left + right) / 2;
    int answer = -INF;
    if (from <= middle)
        answer = max(answer, query(2 * node, left, middle, from, to));
    if (middle + 1 <= to)
        answer = max(answer, query(2 * node + 1, middle + 1, right, from, to));
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        where[x] = i;
    }
    build(1, 1, n);
    for (int i = 1, j = n; i <= n; i++) {
        while (query(1, 1, n, 1, n) <= 0) {
            update(1, 1, n, where[j], where[j], INF);
            update(1, 1, n, 1, where[j], 1);
            j--;
        }
        cout << j + 1 << " ";
        int x;
        cin >> x;
        update(1, 1, n, 1, x, -1);
    }
    return 0;
}