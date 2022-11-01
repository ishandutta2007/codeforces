#include <cstdio>
using namespace std;
int diff(int a, int b) {
    return a > b ? a - b : b - a;
}
int main(){
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if(x1 == x2 && y1 == y2) {
        puts("-1");
    } else if(x1 == x2) {
        int f = diff(y1, y2);
        printf("%d %d %d %d\n", x1 + f, y1, x2 + f, y2);
    } else if(y1 == y2) {
        int f = diff(x1, x2);
        printf("%d %d %d %d\n", x1, y1 + f, x2, y2 + f);
    } else {
        int f = diff(x1, x2), g = diff(y1, y2);
        if(f != g) {
            puts("-1");
        } else {
            int x = x1 < x2 ? x1 : x2;
            int y = y1 < y2 ? y1 : y2;
            int c = 0;
            for(int i = 0; i <= 1; i++)
                for(int j = 0; j <= 1; j++) {
                    int xx = x + f * i, yy = y + f * j;
                    if(!((xx == x1 && yy == y1) || (xx == x2 && yy == y2))) {
                        printf("%d %d%c", xx, yy, c++ ? '\n' : ' ');
                    }
                }
        }
    }
}