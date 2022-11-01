#include <cstdio>

using namespace std;

int pr[2000005];

int a, b, k;

bool check(int l){
     for (int x = a; x <= b - l + 1; ++x) if (pr[x + l - 1] - pr[x - 1] < k) return false;
     return true;
}

int main(){
    for (int i = 2; i * i <= 2000000; ++i)
    if (pr[i] == 0)
    for (int j = i * 2; j <= 2000000; j += i)
    pr[j] = 1;
    for (int i = 2; i <= 2000000; ++i) pr[i] = 1 - pr[i] + pr[i - 1];
    scanf("%d%d%d", &a, &b, &k);
    if (!check(b - a + 1)){printf("-1\n"); return 0;}
    int lo = 1, hi = b - a + 1, mid = (lo + hi) / 2;
    while (lo != hi){
          if (check(mid)) hi = mid;
          else lo = mid + 1;
          mid = (lo + hi) / 2;
    }
    printf("%d\n", mid);
    return 0;
}