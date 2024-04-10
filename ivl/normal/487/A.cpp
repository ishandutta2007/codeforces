#include <cstdio>

using namespace std;

int hy, ay, dy;
int hm, am, dm;
int h, a, d;

int f(int x){
    if (x > 0) return 0;
    return h * (1 - x);
}

int main(){
    scanf("%d%d%d", &hy, &ay, &dy);
    scanf("%d%d%d", &hm, &am, &dm);
    scanf("%d%d%d", &h, &a, &d);
    int r = 1000000000;
    for (int i = 0; i <= 200; ++i)
    for (int j = 0; j <= 200; ++j){
        int y = ay + i - dm;
        int m = am - j - dy;
        if (y <= 0) continue;
        int num = (hm + y - 1) / y;
        int cr = i * a + j * d;
        cr += f(hy - num * m);
        if (cr < r) r = cr;
    }
    printf("%d\n", r);
    return 0;
}