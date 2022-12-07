#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 105;
int n;
double p[N];

struct SB {
    double t;
    int id;
    SB() {}
    SB(double t, int id) {
        this->t = t;
        this->id = id;
    }

    double getr() const {
        return (1 - t * p[id]) / (1 - t);
    }

    bool operator < (const SB& c) const {
        return getr() < c.getr();
    }
};

priority_queue<SB> Q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
        p[i] = 1 - p[i] / 100;
    }
    double ans = n;
    double pp = 1;
    for (int i = 1; i <= n; i++) {
        Q.push(SB(p[i], i));
        pp *= (1 - p[i]);
    }
    for (int i = 1; i <= 1000000; i++) {
        ans += (1 - pp);
        SB u = Q.top(); Q.pop();
        pp *= u.getr();
        u.t *= p[u.id];
        Q.push(u);
    }
    printf("%.20f\n", ans);
    return 0;
}