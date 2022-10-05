#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int ax, ay, bx, by, tx, ty;
int n, s1 = 0, s2 = 0;
double ans;
int x[100010], y[100010];

double dist(int x1, int y1, int x2, int y2){
    return sqrt((ll)(x1 - x2) * (x1 - x2) + (ll)(y1 - y2) * (y1 - y2));
}

int main(){
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", x + i, y + i);
    }
    if(n == 1){
        printf("%.12f", min(dist(ax, ay, x[0], y[0]) + dist(x[0], y[0], tx, ty), dist(bx, by, x[0], y[0]) + dist(x[0], y[0], tx, ty)));
        return 0;
    }
    for(int i = 1; i < n; i++){
        if(dist(tx, ty, x[s1], y[s1]) - dist(ax, ay, x[s1], y[s1]) < dist(tx, ty, x[i], y[i]) - dist(ax, ay, x[i], y[i])) s1 = i;
    }
    if(s1 == 0) s2 = 1;
    for(int i = 1; i < n; i++){
        if(i == s1) continue;
        if(dist(tx, ty, x[s2], y[s2]) - dist(bx, by, x[s2], y[s2]) < dist(tx, ty, x[i], y[i]) - dist(bx, by, x[i], y[i])) s2 = i;
    }
    ans = dist(ax, ay, x[s1], y[s1]) + dist(tx, ty, x[s1], y[s1]) + dist(bx, by, x[s2], y[s2]) + dist(tx, ty, x[s2], y[s2]);
    for(int i = 0; i < n; i++){
        if(i == s1 || i == s2) continue;
        ans += 2 * dist(tx, ty, x[i], y[i]);
    }
    double t = ans;
    ans = 0; s1 = 0;
    for(int i = 1; i < n; i++){
        if(dist(tx, ty, x[s1], y[s1]) - dist(ax, ay, x[s1], y[s1]) < dist(tx, ty, x[i], y[i]) - dist(ax, ay, x[i], y[i])) s1 = i;
    }
    ans = dist(ax, ay, x[s1], y[s1]) + dist(tx, ty, x[s1], y[s1]);
    for(int i = 0; i < n; i++){
        if(i == s1) continue;
        ans += 2 * dist(tx, ty, x[i], y[i]);
    }
    t = min(t, ans);
    ans = 0;
    swap(ax, bx); swap(ay, by);
    s1 = s2 = 0;
    for(int i = 1; i < n; i++){
        if(dist(tx, ty, x[s1], y[s1]) - dist(ax, ay, x[s1], y[s1]) < dist(tx, ty, x[i], y[i]) - dist(ax, ay, x[i], y[i])) s1 = i;
    }
    if(s1 == 0) s2 = 1;
    for(int i = 1; i < n; i++){
        if(i == s1) continue;
        if(dist(tx, ty, x[s2], y[s2]) - dist(bx, by, x[s2], y[s2]) < dist(tx, ty, x[i], y[i]) - dist(bx, by, x[i], y[i])) s2 = i;
    }
    ans = dist(ax, ay, x[s1], y[s1]) + dist(tx, ty, x[s1], y[s1]) + dist(bx, by, x[s2], y[s2]) + dist(tx, ty, x[s2], y[s2]);
    for(int i = 0; i < n; i++){
        if(i == s1 || i == s2) continue;
        ans += 2 * dist(tx, ty, x[i], y[i]);
    }
    t = min(t, ans);
    ans = 0; s1 = 0;
    for(int i = 1; i < n; i++){
        if(dist(tx, ty, x[s1], y[s1]) - dist(ax, ay, x[s1], y[s1]) < dist(tx, ty, x[i], y[i]) - dist(ax, ay, x[i], y[i])) s1 = i;
    }
    ans = dist(ax, ay, x[s1], y[s1]) + dist(tx, ty, x[s1], y[s1]);
    for(int i = 0; i < n; i++){
        if(i == s1) continue;
        ans += 2 * dist(tx, ty, x[i], y[i]);
    }
    t = min(t, ans);
    printf("%.12f", t);
}