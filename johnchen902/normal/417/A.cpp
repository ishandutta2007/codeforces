#include <cstdio>
#include <algorithm>

int main(){
    int c, d, n, m, k;
    scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
    int mini = 999999999;
    for(int x = 0; x <= m; x++){
        int y = n * (m - x) - k;
        if(y < 0)
            y = 0;
        mini = std::min(mini, c * x + d * y);
    }
    printf("%d\n", mini);
    return 0;
}