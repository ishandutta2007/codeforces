#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

int n;
int a[2000];
int b[2000];

void putsb() {
    for(int i = 0; i < n; i++)
        printf("%d%c", b[i] + 1, i != n - 1 ? ' ' : '\n');
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    iota(b, b + n, 0);
    sort(b, b + n, [](int l, int r){ return a[l] < a[r]; });
    int x = -1;
    for(int i = 0; i + 1 < n; i++) {
        if(a[b[i]] == a[b[i + 1]]) {
            if(x == -1)
                x = i;
            else {
                puts("YES");
                putsb();
                swap(b[x], b[x + 1]);
                putsb();
                swap(b[i], b[i + 1]);
                putsb();
                return 0;
            }
        }
    }
    puts("NO");
}