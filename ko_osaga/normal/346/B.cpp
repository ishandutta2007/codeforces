#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

char s1[205], s2[205], s3[205];
int fail[205];
int fail_link[205][26];

int dp[205][205][205];

int f(int x, int y, int d){ 
    if(s3[d] == 0) return -1e9;
    if(s1[x] == 0 || s2[y] == 0) return 0;
    if(~dp[x][y][d]) return dp[x][y][d];
    int ret = max(f(x+1, y, d), f(x, y+1, d));
    if(s1[x] == s2[y]){
        int td = fail_link[d][s1[x] - 'A'];
        if(s3[td] == s1[x]) ret = max(ret, f(x+1, y+1, td+1) + 1);
        else ret = max(ret, f(x+1, y+1, 0) + 1);
    }
    return dp[x][y][d] = ret;
}

void track(int x, int y, int d){
    if(s3[d] == 0 || s1[x] == 0 || s2[y] == 0) return;
    if(f(x, y, d) == f(x+1, y, d)){
        track(x+1, y, d);
        return;
    }
    if(f(x, y, d) == f(x, y+1, d)){
        track(x, y+1, d);
        return;
    }
    if(s1[x] == s2[y]){
        d = fail_link[d][s1[x] - 'A'];
        putchar(s1[x]);
        if(s3[d] == s1[x]){
            track(x+1, y+1, d+1);
        }
        else{
            track(x+1, y+1, 0);
        }
        return;
    }
}

int main(){
    memset(dp,-1,sizeof(dp));
    int crit = 0;
    scanf("%s %s %s",s1, s2, s3);
    for(int i=0; s3[i]; i++){ 
        for(int j=0; j<=i; j++){
            if(strncmp(s3, s3 + i + 1 - j, j) == 0){
                fail[i] = j;
            }
        }
    }
    for(int i=0; s3[i]; i++){
        for(int j=0; j<26; j++){
            int d = i;
            while(d && s3[d] != j + 'A'){
                d = fail[d-1];
            }
            fail_link[i][j] = d;
        }
    }
    int ret = f(0,0,0);
    if(ret == 0){
    	puts("0");
    	return 0;
    }
    else{
        track(0, 0, 0);
    }
}