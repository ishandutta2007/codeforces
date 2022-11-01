#include <cstdio>

using namespace std;

int h;
long long n;

long long rek(int dep, bool com, long long lo, long long hi){
     if (dep == h) return 0;
     long long mid = (lo + hi) / 2;
     long long r = 0;
     if (!com && n > mid || com && n <= mid) r += 2 * (mid - lo + 1) - 1; else com = !com;
     if (n > mid) lo = mid + 1; else hi = mid;
     return r + rek(dep + 1, com, lo, hi) + 1;
}

int main(){
    scanf("%d%I64d", &h, &n);
    printf("%I64d\n", rek(0, false, 1, 1LL << h));
    return 0;
}