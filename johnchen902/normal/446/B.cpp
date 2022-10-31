#include <cstdio>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;

#define int

long long aa[1000], ab[1000];
long long va[1000001], vb[1000001];

signed main(){
    signed n, m, k, p;
    scanf("%d %d %d %d", &n, &m, &k, &p);
    for(signed i = 0; i < n; i++)
        for(signed j = 0; j < m; j++) {
            signed a;
            scanf("%d", &a);
            aa[i] += a;
            ab[j] += a;
        }
    {
        priority_queue<long long> q;
        for(signed i = 0; i < n; i++) q.push(aa[i]);
        for(signed i = 1; i <= k; i++) {
            va[i] = va[i - 1] + q.top();
            q.push(q.top() - (long long) p * m);
            q.pop();
        }
    } {
        priority_queue<long long> q;
        for(signed i = 0; i < m; i++) q.push(ab[i]);
        for(signed i = 1; i <= k; i++) {
            vb[i] = vb[i - 1] + q.top();
            q.push(q.top() - (long long) p * n);
            q.pop();
        }
    }
    bool maxi_set = false;
    long long maxi = 0;
    for(signed i = 0; i <= k; i++) {
        long long val = va[i] + vb[k - i] - (long long) i * (k - i) * p;
        if(!maxi_set || maxi < val) {
            maxi = val;
            maxi_set = true;
        }
    }
    printf("%I64d\n", maxi);
}