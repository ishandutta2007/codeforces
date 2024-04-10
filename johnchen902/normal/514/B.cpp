#include <cstdio>
#include <set>
#include <utility>
#include <cstdlib>
#include <algorithm>
using namespace std;
set<pair<int, int>> s;
int main(){
    int n, x0, y0;
    scanf("%d %d %d", &n, &x0, &y0);
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x -= x0; y -= y0;
        if(x == 0) {
            s.insert({0, 1});
        } else if(y == 0) {
            s.insert({1, 0});
        } else {
            if(x < 0)
                x = -x, y = -y;
            int gcd = __gcd(x, abs(y));
            x /= gcd, y /= gcd;
            s.insert({x, y});
        }
    }
    printf("%d\n", (int) s.size());
}