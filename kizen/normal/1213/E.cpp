#include <bits/stdc++.h>

using namespace std;

const int NS = (int)3e5 + 4;
int N;
int chk[6][6];

int main(){
    scanf("%d", &N);
    char s[6];
    scanf("%s", s);
    for(int i = 1; i <= 3; ++i) for(int j = 1; j <= 3; ++j) chk[i][j] = 1;
    chk[s[0] - 'a' + 1][s[1] - 'a' + 1] = 0;
    scanf("%s", s);
    chk[s[0] - 'a' + 1][s[1] - 'a' + 1] = 0;
    if(chk[1][3] + chk[3][2] + chk[2][1] == 3){
        puts("YES");
        for(int i = 1; i <= N; ++i) printf("acb");
        return 0;
    }
    if(chk[1][2] + chk[2][3] + chk[3][1] == 3){
        puts("YES");
        for(int i = 1; i <= N; ++i) printf("abc");
        return 0;
    }
    for(int i = 1; i <= 3; ++i){
        int j = 1, x = 2;
        if(j == i) ++j;
        if(x == i || x == j) ++x;
        if(chk[i][i] + chk[j][x] + chk[x][j] == 3){
            if(chk[i][j]){
                puts("YES");
                for(int I = 1; I <= N; ++I) printf("%c", 'a' + i - 1);
                for(int I = 1; I <= N; ++I) printf("%c%c", 'a' + j - 1, 'a' + x - 1);
                return 0;
            }
            if(chk[i][x]){
                puts("YES");
                for(int I = 1; I <= N; ++I) printf("%c", 'a' + i - 1);
                for(int I = 1; I <= N; ++I) printf("%c%c", 'a' + x - 1, 'a' + j - 1);
                return 0;
            }
            if(chk[x][i]){
                puts("YES");
                for(int I = 1; I <= N; ++I) printf("%c%c", 'a' + j - 1, 'a' + x - 1);
                for(int I = 1; I <= N; ++I) printf("%c", 'a' + i - 1);
                return 0;
            }
            if(chk[j][i]){
                puts("YES");
                for(int I = 1; I <= N; ++I) printf("%c%c", 'a' + x - 1, 'a' + j - 1);
                for(int I = 1; I <= N; ++I) printf("%c", 'a' + i - 1);
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}