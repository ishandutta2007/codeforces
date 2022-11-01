#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int r, x1, y1, x2, y2;
    scanf("%d %d %d %d %d", &r, &x1, &y1, &x2, &y2);
    printf("%d\n", (int) ceil(hypot(x1 - x2, y1 - y2) / (2 * r)));
}