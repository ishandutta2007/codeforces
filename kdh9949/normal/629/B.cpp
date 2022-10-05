#include <cstdio>
#include <algorithm>
using namespace std;

char gend[3];
int ms[368], fs[368];
int n, s, e;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%d%d", gend, &s, &e);
        for(int j = s; j <= e; j++){
            if(gend[0] == 'M') ms[j]++;
            else fs[j]++;
        }
    }
    int ans = 0;
    for(int i = 1; i <= 366; i++){
        ans = max(ans, min(ms[i], fs[i]) * 2);
    }
    printf("%d", ans);
}