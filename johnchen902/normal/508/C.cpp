#include <cstdio>
#include <algorithm>
using namespace std;

bool x[301];

int main(){
    int m, t, r;
    scanf("%d %d %d", &m, &t, &r);
    if(t < r) {
        puts("-1");
        return 0;
    }

    int l = 0, d = 0;
    for(int i = 0; i < m; i++) {
        int w; scanf("%d", &w);
        if(w - l < t) {
            // [0, t-w+l) -> [w-l, t)
            copy_backward(x, x + t - (w - l), x + t);
            fill(x, x + (w - l), false);
        } else {
            fill(x, x + t, false);
        }
        int c = r - count(x, x + t, true);
        for(int j = 0; c > 0; j++)
            if(!x[j]) {
                x[j] = true;
                c--;
                d++;
            }
        l = w;
    }

    printf("%d\n", d);
}