#include <cstdio>

using namespace std;

int n, m;
char in[1005];

bool cnt[1005];

int main(){
    scanf("%d%d", &n, &m);
    int r = 0;
    for (int i = 0; i < n; ++i){
        scanf("%s", in);
        int t = 0;
        for (int j = 0; j < m; ++j){
            if (in[j] == 'G') t -= j;
            if (in[j] == 'S') t += j;
        }
        if (t < 0){
           printf("-1\n");
           return 0;
        }
        if (!cnt[t]) ++r;
        cnt[t] = true;
    }
    printf("%d\n", r);
    return 0;
}