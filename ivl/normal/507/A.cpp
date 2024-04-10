#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int a[100005];
int b[100005];

bool cmp(int x, int y){return a[x] < a[y];}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + (b[i] = i));
    sort(b, b + n, cmp);
    int r = 0;
    for (int i = 0; i < n; ++i) if (k >= a[b[i]]){
        ++r;
        k -= a[b[i]];
    }
    printf("%d\n", r);
    for (int i = 0; i < r; ++i) printf("%d ", b[i] + 1); printf("\n");
    return 0;
}