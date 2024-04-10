#include <cstdio>
#include <algorithm>
#define x first
#define y second

using namespace std;

pair < int, int > t[10];
int x[5], y[5];

int main(){
    for (int i = 0; i < 8; ++i) scanf("%d%d", &(t[i].x), &(t[i].y));
    sort(t, t + 8);
    x[0] = t[0].x, x[1] = t[3].x, x[2] = t[5].x;
    y[0] = t[0].y, y[1] = t[1].y, y[2] = t[2].y;
    bool test = (x[0] != x[1]) && (x[1] != x[2]) && (y[0] != y[1]) && (y[0] != y[2]) && (y[1] != y[2]);
    int poin = 0;
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (i == 1 && j == 1) continue;
            if (t[poin].x != x[i] || t[poin].y != y[j]){
               test = false;
            }
            ++poin;
        }
    }
    if (test) printf("respectable\n");
    else printf("ugly\n");
    return 0;
}