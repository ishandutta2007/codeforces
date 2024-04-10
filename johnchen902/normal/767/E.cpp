#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int c[100000], w[100000], note[100000], coin[100000];
struct Cmp {
    bool operator() (int lhs, int rhs) {
        return (100LL - coin[lhs]) * w[lhs] > (100LL - coin[rhs]) * w[rhs];
    }
};
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", c + i);
    for(int i = 0; i < n; i++)
        scanf("%d", w + i);
    long long ans = 0;
    priority_queue<int, vector<int>, Cmp> pq;
    for(int i = 0; i < n; i++) {
        note[i] = c[i] / 100;
        coin[i] = c[i] % 100;
        if(coin[i] == 0)
            continue;
        m -= coin[i];
        pq.push(i);
        if(m < 0) {
            int x = pq.top();
            pq.pop();
            ans += (100LL - coin[x]) * w[x];
            note[x]++;
            coin[x] = 0;
            m += 100;
        }
    }
    printf("%lld\n", ans);
    for(int i = 0; i < n; i++)
        printf("%d %d\n", note[i], coin[i]);
}