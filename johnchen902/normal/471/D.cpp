#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int a[200000], b[200000];
int len;
int s[400000], z[400000];

int strcmpn(int i, int j) {
    int k = 0;
    while(i < len && j < len && s[i] == s[j])
        i++, j++, k++;
    return k;
}

int main(){
    // read input
    int n, w;
    scanf("%d %d", &n, &w);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    for(int i = 0; i < w; i++) scanf("%d", b + i);

    // special case
    if(w == 1) { printf("%d\n", n); return 0; }
    if(n == 1) { printf("%d\n", 0); return 0; }

    // generate string
    for(int i = 0; i < w - 1; i++) s[len++] = b[i + 1] - b[i];
    for(int i = 0; i < n - 1; i++) s[len++] = a[i + 1] - a[i];

    // z-value algorithm
    z[0] = len;
    z[1] = strcmpn(0, 1);
    for(int i = 2, l = 1, r = 1 + z[1]; i < len; i++) {
        if(r <= i) {
            z[i] = strcmpn(0, i);
            l = i;
            r = i + z[i];
        } else if(i + z[i - l] < r){
            z[i] = z[i - l];
        } else {
            z[i] = (r - i) + strcmpn(r - i, r);
            l = i;
            r = i + z[i];
        }
    }

    // getting result
    printf("%d\n", count_if(z + w - 1, z + len, bind2nd(greater_equal<int>(), w - 1)));
}