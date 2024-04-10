#include <cstdio>
#include <algorithm>

using namespace std;

int gr[100005];
int un(int x){
    if (x == gr[x]) return x;
    return gr[x] = un(gr[x]);
}
void join(int a, int b){
     a = un(a);
     b = un(b);
     if (a == b) return;
     gr[a] = b;
}

int n, m, k;
int c[505];
int e[100005][3];

int dis[505][505];

int main(){
    for (int i = 0; i < 100005; ++i) gr[i] = i;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) scanf("%d", c + i);
    for (int i = 0; i < m; ++i){
        scanf("%d%d%d", e[i], e[i] + 1, e[i] + 2);
        if (e[i][2] == 0) join(e[i][0], e[i][1]);
    }
    int p = 1;
    bool check = true;
    for (int i = 0; i < k; ++i){
        int root = un(p);
        for (int j = 0; j < c[i]; ++j){
            if (un(p + j) != root) check = false;
        }
    p += c[i];
    }
    if (!check){
       printf("No\n");
       return 0;
    }
    printf("Yes\n");
    p = 1;
    for (int i = 0; i < k; ++i){
        for (int j = 0; j < c[i]; ++j){
            gr[p + j] = i;
        }
        p += c[i];
    }
    for (int i = 0; i < k; ++i) for (int j = 0; j < k; ++j) dis[i][j] = 1000000000;
    for (int i = 0; i < k; ++i) dis[i][i] = 0;
    for (int i = 0; i < m; ++i){
        int a = e[i][0] = gr[e[i][0]];
        int b = e[i][1] = gr[e[i][1]];
        dis[a][b] = dis[b][a] = min(dis[a][b], e[i][2]);
    }
    for (int l = 0; l < k; ++l)
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                if (dis[i][l] + dis[l][j] < dis[i][j]) dis[i][j] = dis[i][l] + dis[l][j];
    for (int i = 0; i < k; ++i){
        for (int j = 0; j < k; ++j) printf("%d ", (dis[i][j] == 1000000000) ? -1 : dis[i][j]);
        printf("\n");
    }
    return 0;
}