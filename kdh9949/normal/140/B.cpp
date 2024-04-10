#include <bits/stdc++.h>
using namespace std;

int n;
int a[301][301];
int mx[301], smx[301];
int srt[301];
int pos[301][301], spos[301];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) scanf("%d", a[i] + j);
    for(int i = 1; i <= n; i++) scanf("%d", srt + i);
    for(int i = 1; i <= n; i++) spos[srt[i]] = i;
    mx[0] = 1;
    for(int i = 1; i <= n; i++){
        if(spos[mx[i - 1]] > spos[i]) mx[i] = i;
        else mx[i] = mx[i - 1];
    }
    for(int i = 2; i <= n; i++){
        int cur = -1;
        for(int j = 1; j <= i; j++){
            if(j == mx[i]) continue;
            if(cur == -1) cur = j;
            if(spos[j] < spos[cur]) cur = j;
        }
        smx[i] = cur;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pos[i][a[i][j]] = j;
        }
    }
    for(int i = 1; i <= n; i++){
        int cur = -1, val = n + 1;
        for(int j = 1; j <= n; j++){
            if(mx[j] == i){
                if(j == 1) continue;
                if(pos[i][smx[j]] < val) val = pos[i][smx[j]], cur = j;
            }
            else{
                if(pos[i][mx[j]] < val) val = pos[i][mx[j]], cur = j;
            }
        }
        printf("%d ", cur);
    }
}