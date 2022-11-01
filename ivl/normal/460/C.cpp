#include <cstdio>

using namespace std;

int n, m, w;

int a[100005];

int pr[200005];
bool attempt(int x){
    for (int i = 0; i < n; ++i) pr[i] = 0;
    int cnt = 0, prs = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] + prs < x){
           int r = x - a[i] - prs;
           cnt += r;
           pr[i] += r;
           pr[i + w - 1] -= r;
        }
        prs += pr[i];
        if (cnt > m) return false;
    }
    return true;
}

int main(){
    scanf("%d%d%d", &n, &m, &w);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int lo = 0, hi = 1100000000, mid = (lo + hi) / 2;
    while (lo != hi){
          if (attempt(mid)) lo = mid;
          else hi = mid - 1;
          mid = (lo + hi + 1) / 2;
    }
    printf("%d\n", lo);
    return 0;
}