#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[300005];

int s[300005];

int b[300005];

bool cmp(int x, int y){
     return a[x] < a[y];
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) s[i] = i;
    sort(s, s + n, cmp);
    b[s[0]] = a[s[0]];
    for (int i = 1; i < n; ++i){
        b[s[i]] = max(a[s[i]], b[s[i - 1]] + 1);
    }
    for (int i = 0; i < n; ++i) printf("%d ", b[i]);
    printf("\n");
    return 0;
}