#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
char board[1010][1010];
int r[1010], c[1010];
int cnt;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%s", board[i] + 1);
        for(int j = 1; j <= m; j++){
            if(board[i][j] == '*') {r[i]++; c[j]++; cnt++;}
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if((r[i] + c[j]) - (board[i][j] == '*') == cnt){
                printf("YES\n%d %d", i, j);
                return 0;
            }
        }
    }
    puts("NO");
}