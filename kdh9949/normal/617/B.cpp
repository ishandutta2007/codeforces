#include <cstdio>

long long ans = 1;
int n, cur, last;
bool flag;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &cur);
        if(cur == 1) flag = true, ans *= (long long)(last + 1), last = 0;
        else if(flag) last++;
    }
    printf("%I64d", flag ? ans : 0);
}