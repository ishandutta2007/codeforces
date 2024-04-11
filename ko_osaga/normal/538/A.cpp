#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[105], s2[11] = "CODEFORCES";
int dp[105][11];

int f(int x, int y){
    if(str[x] == 0 || y == 10) return 0;
    if(~dp[x][y]) return dp[x][y];
    int ret = max(f(x+1,y),max(f(x,y+1),f(x+1,y+1) + (str[x] == s2[y])));
    return dp[x][y] = ret;
}

int main(){
    scanf("%s",str);
    int l =(int)strlen(str);
    if(l < 10){
        puts("NO");
        return 0;
    }
    int ret = 0;
    for (int i=0; i<=10; i++) {
        int p = 0;
        int found = 1;
        for (int j=0; j<i; j++) {
            if(s2[p++] != str[j]) found = 0;
        }
        for (int j=l-10+i; j<l; j++) {
            if(s2[p++] != str[j]) found = 0;
        }
        ret |= found;
    }
    printf(ret? "YES" : "NO");
}