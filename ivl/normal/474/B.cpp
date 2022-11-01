#include <cstdio>

using namespace std;

int n;
long long a[100005];
int m;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%I64d", a + i);
        if (i > 0) a[i] += a[i - 1];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i){
        long long q;
        scanf("%I64d", &q);
        int lo = 0, hi = n - 1, mid = (lo + hi) / 2;
        while (lo != hi){
              if (a[mid] < q) lo = mid + 1;
              else hi = mid;
              mid = (lo + hi) / 2;
        }
        printf("%d\n", lo + 1);
    }
    return 0;
}