#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[100005];
int dir[100005];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int lo = 1000000, hi = -1;
    for (int i = 0; i < n - 1; ++i){
        dir[i] = (a[i] < a[i + 1]);
        if (dir[i] == 0){
           if (i < lo) lo = i;
           hi = i;
        }
    }
    if (hi < lo){printf("yes\n1 1\n"); return 0;}
    for (int i = lo, j = hi + 1; i <= j; ++i, --j){
        swap(a[i], a[j]);
    }
    bool ch = true;
    for (int i = 0; i < n - 1; ++i) if (a[i] > a[i + 1]) ch = false;
    if (ch) printf("yes\n%d %d\n", lo + 1, hi + 2);
    else printf("no\n");
    return 0;
}