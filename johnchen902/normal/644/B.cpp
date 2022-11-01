#include <cstdio>
#include <queue>
int main() {
    int n, b;
    std::scanf("%d %d", &n, &b);
    std::queue<long long> qu;
    long long time = 0;
    for(int i = 0; i < n; i++) {
        int t, d;
        std::scanf("%d %d", &t, &d);
        while(!qu.empty() && qu.front() <= t)
            qu.pop();
        if((int) qu.size() > b) {
            std::printf("-1%c", " \n"[i == n - 1]);
        } else {
            if(time < t)
                time = t;
            time += d;
            std::printf("%lld%c", time, " \n"[i == n - 1]);
            qu.push(time);
        }
    }
}