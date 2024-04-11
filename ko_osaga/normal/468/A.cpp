#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    if(n<4){
        puts("NO");
        return 0;
    }
    puts("YES");
    if(n == 4){
        puts("4 * 3 = 12");
        puts("12 * 2 = 24");
        puts("24 * 1 = 24");
    }
    if(n == 5){
        puts("5 * 3 = 15");
        puts("4 * 2 = 8");
        puts("15 + 8 = 23");
        puts("23 + 1 = 24");
    }
    if(n == 6){
        puts("4 + 1 = 5");
        puts("6 * 5 = 30");
        puts("30 - 5 = 25");
        puts("25 - 3 = 22");
        puts("22 + 2 = 24");
    }
    if(n == 7){
        puts("7 * 6 = 42");
        puts("5 * 4 = 20");
        puts("42 - 20 = 22");
        puts("22 + 3 = 25");
        puts("25 - 2 = 23");
        puts("23 + 1 = 24");
    }
    if(n >= 8){
        puts("8 - 7 = 1");
        puts("6 - 5 = 1");
        puts("1 - 1 = 0");
        for (int i=9; i<=n; i++) {
            printf("%d * 0 = 0\n",i);
        }
        puts("4 * 3 = 12");
        puts("12 * 2 = 24");
        puts("24 * 1 = 24");
        puts("24 + 0 = 24");
    }
}