#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct Pt {
    int id, x, y;
} pt[100000];
struct Angle {
    Pt a, b;
    Angle(const Pt &aa, const Pt &bb) : a(aa), b(bb) {}
    int product() const {
        return a.x * b.x + a.y * b.y;
    }
    int cross() const {
        return a.x * b.y - a.y * b.x;
    }
};
bool operator < (const Angle &lhs, const Angle &rhs) {
    if(lhs.cross() <= 0 && rhs.cross() >= 0)
        return false;
    if(lhs.cross() >= 0 && rhs.cross() <= 0)
        return true;
    if(lhs.product() <= 0 && rhs.product() >= 0)
        return false;
    if(lhs.product() >= 0 && rhs.product() <= 0)
        return true;
    return (long long) lhs.cross() * rhs.product() < (long long) rhs.cross() * lhs.product();
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &pt[i].x, &pt[i].y);
        pt[i].id = i + 1;
    }
    sort(pt, pt + n, [](const Pt &lhs, const Pt &rhs) {
        return atan2(lhs.y, lhs.x) < atan2(rhs.y, rhs.x);
    });
    Angle ans(pt[n - 1], pt[0]);
    for(int i = 0; i + 1 < n; i++)
        ans = min(ans, Angle(pt[i], pt[i + 1]));
    printf("%d %d\n", ans.a.id, ans.b.id);
}