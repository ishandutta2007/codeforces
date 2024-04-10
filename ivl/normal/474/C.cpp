#include <cstdio>
#include <algorithm>
#define x first
#define y second

using namespace std;

int n;
int x[10], y[10], a[10], b[10];

int rotate(int t){
     x[t] -= a[t];
     y[t] -= b[t];
     swap(x[t], y[t]);
     x[t] = -x[t];
     x[t] += a[t];
     y[t] += b[t];
     return 0;
}

pair < int, int > rotate(pair < int, int > t, pair < int, int > t2){
     t.x -= t2.x;
     t.y -= t2.y;
     swap(t.x, t.y);
     t.x = -t.x;
     t.x += t2.x;
     t.y += t2.y;
     return t;
}

bool check(){
     if (x[0] == x[1] && y[0] == y[1]) return false;
     // 0 1 2 3
     #define a 0
     #define b 1
     #define c 2
     #define d 3
     if (rotate(make_pair(x[a], y[a]), make_pair(x[b], y[b])) == make_pair(x[c], y[c]))
     if (rotate(make_pair(x[b], y[b]), make_pair(x[c], y[c])) == make_pair(x[d], y[d]))
     if (rotate(make_pair(x[c], y[c]), make_pair(x[d], y[d])) == make_pair(x[a], y[a]))
     if (rotate(make_pair(x[d], y[d]), make_pair(x[a], y[a])) == make_pair(x[b], y[b]))
     return true;
     
     // 0 1 3 2
     #define a 0
     #define b 1
     #define c 3
     #define d 2
     if (rotate(make_pair(x[a], y[a]), make_pair(x[b], y[b])) == make_pair(x[c], y[c]))
     if (rotate(make_pair(x[b], y[b]), make_pair(x[c], y[c])) == make_pair(x[d], y[d]))
     if (rotate(make_pair(x[c], y[c]), make_pair(x[d], y[d])) == make_pair(x[a], y[a]))
     if (rotate(make_pair(x[d], y[d]), make_pair(x[a], y[a])) == make_pair(x[b], y[b]))
     return true;
     
     // 0 2 1 3
     #define a 0
     #define b 2
     #define c 1
     #define d 3
     if (rotate(make_pair(x[a], y[a]), make_pair(x[b], y[b])) == make_pair(x[c], y[c]))
     if (rotate(make_pair(x[b], y[b]), make_pair(x[c], y[c])) == make_pair(x[d], y[d]))
     if (rotate(make_pair(x[c], y[c]), make_pair(x[d], y[d])) == make_pair(x[a], y[a]))
     if (rotate(make_pair(x[d], y[d]), make_pair(x[a], y[a])) == make_pair(x[b], y[b]))
     return true;
     
     // 0 2 3 1
     #define a 0
     #define b 2
     #define c 3
     #define d 1
     if (rotate(make_pair(x[a], y[a]), make_pair(x[b], y[b])) == make_pair(x[c], y[c]))
     if (rotate(make_pair(x[b], y[b]), make_pair(x[c], y[c])) == make_pair(x[d], y[d]))
     if (rotate(make_pair(x[c], y[c]), make_pair(x[d], y[d])) == make_pair(x[a], y[a]))
     if (rotate(make_pair(x[d], y[d]), make_pair(x[a], y[a])) == make_pair(x[b], y[b]))
     return true;
     
     // 0 3 1 2
     #define a 0
     #define b 3
     #define c 1
     #define d 2
     if (rotate(make_pair(x[a], y[a]), make_pair(x[b], y[b])) == make_pair(x[c], y[c]))
     if (rotate(make_pair(x[b], y[b]), make_pair(x[c], y[c])) == make_pair(x[d], y[d]))
     if (rotate(make_pair(x[c], y[c]), make_pair(x[d], y[d])) == make_pair(x[a], y[a]))
     if (rotate(make_pair(x[d], y[d]), make_pair(x[a], y[a])) == make_pair(x[b], y[b]))
     return true;
     
     // 0 3 2 1
     #define a 0
     #define b 3
     #define c 2
     #define d 1
     if (rotate(make_pair(x[a], y[a]), make_pair(x[b], y[b])) == make_pair(x[c], y[c]))
     if (rotate(make_pair(x[b], y[b]), make_pair(x[c], y[c])) == make_pair(x[d], y[d]))
     if (rotate(make_pair(x[c], y[c]), make_pair(x[d], y[d])) == make_pair(x[a], y[a]))
     if (rotate(make_pair(x[d], y[d]), make_pair(x[a], y[a])) == make_pair(x[b], y[b]))
     return true;
     
     return false;
}

#undef a
#undef b
#undef c
#undef d


int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 4; ++j){
            scanf("%d%d%d%d", x + j, y + j, a + j, b + j);
        }
        int r = 10000;
        for (int r1 = 0; r1 < 4; ++r1, rotate(0))
        for (int r2 = 0; r2 < 4; ++r2, rotate(1))
        for (int r3 = 0; r3 < 4; ++r3, rotate(2))
        for (int r4 = 0; r4 < 4; ++r4, rotate(3))
        if (check()) r = min(r, r1 + r2 + r3 + r4);
        if (r == 10000) r = -1;
        printf("%d\n", r);
    }
    return 0;
}