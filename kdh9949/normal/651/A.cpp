#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1011][1011];
bool chk[1011][1011];
int a, b;

int f(int a, int b){
    if(a < 0 || b < 0) return -987654321;
    if(a == 0 || b == 0) return 0;
    if(chk[a][b]) return dp[a][b];
    dp[a][b] = max(f(a - 2, b + 1), f(a + 1, b - 2)) + 1;
    chk[a][b] = true;
    return dp[a][b];
}

int main(){
    scanf("%d%d", &a, &b);
    //printf("%d", f(a, b));
    int cnt = 0;
    while(a > 0 && b > 0){
        if(a == 1 && b == 1) break;
        else if(a == 1) a++, b -= 2;
        else if(b == 1) b++, a -= 2;
        else if(a > b) a -= 2, b++;
        else b -= 2, a++;
        cnt++;
    }
    printf("%d", cnt);
}