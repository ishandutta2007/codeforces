#include <cstdio>

int k, q, cnt;
int ans[2][1025][1025];

void f(int t){
    if(t == q) return;
    for(int i = 0; i < t; i++){
        for(int j = 0; j < 2 * t; j++){
            ans[cnt % 2][i][j] = ans[(cnt + 1)%2][i][j / 2];
        }
    }
    for(int i = 0; i < t; i++){
        for(int j = 0; j < 2 * t; j++){
            ans[cnt % 2][i + t][j] = (ans[cnt % 2][i][j] + (j % 2)) % 2;
        }
    }
    cnt++;
    f(t * 2);
}

int main(){
    scanf("%d", &k);
    if(k == 0){
        puts("+");
        return 0;
    }
    q = (1 << k);
    f(1);
    cnt++;
    for(int i = 0; i < q; i++){
        for(int j = 0; j < q; j++){
            putchar(ans[cnt % 2][i][j] ? '+' : '*');
        }
        puts("");
    }
}