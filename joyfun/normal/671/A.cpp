#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100005;

struct Point {
    double x, y;
    void read() {
        scanf("%lf%lf", &x, &y);
    }
} a[2], t, p[N];

double dist(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int n;

double Max[2][2];
int Maxv[2][2];

int main() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            Max[i][j] = -1e18;
    a[0].read(); a[1].read(); t.read();
    scanf("%d", &n);
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        p[i].read();
        sum += 2 * dist(p[i], t);
        for (int j = 0; j < 2; j++) {
            double tmp = dist(p[i], t) - dist(a[j], p[i]);
            if (Max[j][0] < tmp) {
                Maxv[j][1] = Maxv[j][0];
                Max[j][1] = Max[j][0];
                Max[j][0] = tmp;
                Maxv[j][0] = i;
            } else if (Max[j][1] < tmp) {
                Max[j][1] = tmp;
                Maxv[j][1] = i;
            }
        }
    }
   // for (int i = 0; i < 2; i++) {
     //   for (int j = 0; j < 2; j++) {
       //     printf("%d %d %f %d\n", i, j, Max[i][j], Maxv[i][j]);
        //}
    //}
    double ans = min(sum - Max[0][0], sum - Max[1][0]);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (Maxv[0][i] != Maxv[1][j]) {
                ans = min(ans, sum - Max[0][i] - Max[1][j]);
            }
        }
    }
    printf("%.12f\n", ans);
    return 0;
}