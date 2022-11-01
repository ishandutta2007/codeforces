#include <cstdio>
#include <algorithm>

using namespace std;

char in[100005];
int n;
int m;

int x[100005], y[100005], z[100005];

int main(){
    scanf("%s", in);
    while (in[++n] != '\0');
    x[0] = y[0] = z[0] = 0;
    for (int i = 1; i <= n; ++i){
        x[i] = x[i - 1];
        y[i] = y[i - 1];
        z[i] = z[i - 1];
        if (in[i - 1] == 'x') ++x[i];
        if (in[i - 1] == 'y') ++y[i];
        if (in[i - 1] == 'z') ++z[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        int d = x[b] - x[a - 1], e = y[b] - y[a - 1], f = z[b] - z[a - 1];
        if (b - a + 1 < 3) d = e = f = 0;
        if (max(max(d, e), f) - min(min(d, e), f) <= 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}