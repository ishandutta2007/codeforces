#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define X first
#define Y second

const int N = 5005;

int n, m, r, c[N];
pii a[N];
char b[N][N];

int main(){
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++) a[i].Y = i;
    for(int i = 0; i < m; i++) scanf("%s", b[i]);
    for(int i = 0; i < n; i++){
        fill(c, c + m, 0);
        int j = 0; for(int k = 0; k < m; k++){
            if(b[a[k].Y][i] - '0'){
                c[a[k].Y] = 1;
                a[k].X++;
                a[j++] = a[k];
                r = max(r, j * a[k].X);
            }
        }
        for(int k = 0; k < m; k++) if(!c[k]) a[j++] = {0, k};
    }
    printf("%d\n", r);
}