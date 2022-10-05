#include <cstdio>

int n, rs[101], cs[101], ans;
char input[111];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", input);
        for(int j = 0; j < n; j++){
            if(input[j] == 'C') rs[j]++, cs[i]++;
        }
    }
    for(int i = 0; i < n; i++) ans += rs[i] * (rs[i] - 1) / 2 + cs[i] * (cs[i] - 1) / 2;
    printf("%d", ans);
}