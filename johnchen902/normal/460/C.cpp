#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, w;
int a[100000];
int b[100000];
bool possible(int x) {
    fill_n(b, n, 0);
    int mm = 0;
    int hh = 0;
    for(int i = 0; i < n; i++) {
        if(i >= w) hh -= b[i - w];
        if(a[i] + hh < x) {
            b[i] = x - (a[i] + hh);
            mm += b[i];
            hh += b[i];
            if(mm > m) return false;
        }
    }
    return true;
}
int main(){
    scanf("%d %d %d", &n, &m, &w);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    int l = *min_element(a, a + n);
    int r = l + m + 1;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        (possible(mid) ? l : r) = mid;
    }
    printf("%d\n", l);
}