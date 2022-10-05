#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, p;

struct BIT{
    int d[N];
    void u(int x){ for(; x <= n; x += x & -x) d[x] ^= 1; }
    int g(int x){ int r = 0; for(; x; x &= x - 1) r ^= d[x]; return r; }
} B;

int main(){
    scanf("%d", &n);
    for(int i = 1, x; i <= n; i++){
        scanf("%d", &x);
        p ^= B.g(x);
        p ^= B.g(n);
        B.u(x);
    }
    puts((p ^ (~n & 1)) ? "Petr" : "Um_nik");
}