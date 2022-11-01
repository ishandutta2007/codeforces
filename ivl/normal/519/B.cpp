#include <cstdio>

using namespace std;

int XOR(int *r, int l){
    int R = 0;
    for (int i = 0; i < l; ++i) R ^= r[i];
    return R;
}
int XOR(int *r){return XOR(r, 100000);}

int n;
int a[100005];
int b[100005];
int c[100005];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n - 1; ++i) scanf("%d", b + i);
    for (int i = 0; i < n - 2; ++i) scanf("%d", c + i);
    printf("%d\n%d\n", XOR(a) ^ XOR(b), XOR(b) ^ XOR(c));
    return 0;
}