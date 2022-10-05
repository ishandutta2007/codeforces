#include <cstdio>
#include <algorithm>

int n, m;
char str[100010], tar[33];
bool flag;
int chk[100010];
int ans, last;

int main(){
    scanf("%s%s", str, tar);
    for(; str[++n]; );
    for(; tar[++m]; );
    for(int i = 0; i < n; i++){
        flag = true;
        for(int j = 0; j < m; j++){
            if(tar[j] != str[i + j]) flag = false;
        }
        if(flag) chk[i] = 1;
    }
    last = -1;
    for(int i = 0; i < n; i++){
        if(chk[i]){
            if(last == -1) last = i;
            else if(i - last >= m) last = i, ans++;
        }
    }
    printf("%d", last == -1 ? 0 : ans + 1);
}