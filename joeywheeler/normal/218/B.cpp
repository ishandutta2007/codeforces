#include <cstdio>
#include <queue>

using namespace std;

struct minimizer {
    int v;
};

bool operator<(const minimizer &a, const minimizer &b) {
    return a.v > b.v;
}

priority_queue<minimizer> mn;
priority_queue<int> mx;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int tmp;
        scanf("%d", &tmp);
        mx.push(tmp);
        mn.push((minimizer) {tmp});
    }

    int maxi = 0, mini = 0;
    for (int i = 0; i < n; i++) {
        maxi += mx.top();
        mx.push(mx.top() - 1);
        mx.pop();
        while (mn.top().v == 0) mn.pop();
        int tmp = mn.top().v - 1;
        mini += mn.top().v;
        mn.pop();
        mn.push((minimizer) {tmp});
    }
    printf("%d %d\n", maxi, mini);
}