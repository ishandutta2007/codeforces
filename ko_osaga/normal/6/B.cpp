#include <cstdio>
#include <algorithm>
using namespace std;

char str[105][105], c[5];
int n,m;

int col[256];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int main(){
    scanf("%d %d %s",&n,&m,c);
    for (int i=1; i<=n; i++) {
        scanf("%s",str[i]+1);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            for (int k=0; k<4; k++) {
                if(str[i + dx[k]][j + dy[k]] == c[0]){
                    col[str[i][j]] = 1;
                }
            }
        }
    }
    int ret = 0;
    for (int i=0; i<256; i++) {
        if(i == c[0] ||i == '.') continue;
        ret += col[i];
    }
    printf("%d",ret);
}