#include <cstdio>

long long a, b;
int ans;

int main(){
    scanf("%I64d%I64d", &a, &b);
    for(int i = 2; i <= 63; i++){
        for(int j = 0; j < i - 1; j++){
            long long cur = ((1ll << i) - 1) - (1ll << j);
            if(a <= cur && cur <= b) ans++;
        }
    }
    printf("%d", ans);
}