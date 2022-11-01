#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int gcd(int a, int b){
    while (b){a %= b; swap(a, b);}
    return a;
}
pair < int, int > reduce(int a, int b){
     int x = gcd(a, b);
     a /= x;
     b /= x;
     if (a < 0) a = -a, b = -b;
     if (a == 0 && b < 0) b = -b;
     return make_pair(a, b);
}

int n, x0, y0;
map < pair < int, int >, bool > M;

int main(){
    scanf("%d%d%d", &n, &x0, &y0); int R = 0;
    for (int i = 0; i < n; ++i){
        int x, y; scanf("%d%d", &x, &y);
        x -= x0, y -= y0;
        if (!M[reduce(x, y)]++) ++R;
    } printf("%d\n", R);
    return 0;
}