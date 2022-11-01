#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[3005];
char name[3005][15], name_pom[15];
int pos[3005];
int h[3005];
int pos_h[3005];

bool msort1(int x, int y){
    return a[x] < a[y];
}

bool msort2(int x, int y){
    return h[x] > h[y];
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%s %d", name_pom, a + i);
        for (int j = 0; j < 15; ++j){
            name[i][j] = name_pom[j];
        }
        pos[i] = pos_h[i] = i;
    }
    sort(pos, pos + n, msort1);
    for (int i = 0; i < n; ++i){
        if (a[pos[i]] > i){
            printf("-1\n");
            return 0;
        }
        h[pos[i]] = h[pos_h[0]] - a[pos[i]] + 1;
        for (int j = 0; j < a[pos[i]]; ++j){
            ++h[pos_h[j]];
        }
        sort(pos_h, pos_h + n, msort2);
    }
    for (int i = 0; i < n; ++i){
        printf("%s %d\n", name[pos[i]], h[pos[i]]);
    }
    return 0;
}