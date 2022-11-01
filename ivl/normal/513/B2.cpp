#include <cstdio>

using namespace std;

int out[100005];

int main(){
    int n;
    long long m;
    scanf("%d%I64d", &n, &m);
    int lo = 0, hi = n - 1;
    for (int i = 1; i <= n; ++i){
        if (n == i){out[lo] = n; continue;}
        long long x = (1LL << (n - i - 1));
        if (m <= x) out[lo++] = i;
        else {
             m -= x;
             out[hi--] = i;
        }
    }
    for (int i = 0; i < n; ++i) printf("%d ", out[i]); printf("\n");
    return 0;
}