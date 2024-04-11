#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int dx[5005][5005];

int main(){
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        char str[5005];
        scanf("%s",str);
        str[m] = '0';
        int sess = 0, st = 0;
        for (int j=0; j<=m; j++) {
            if(!sess && str[j] == '1'){
                sess = 1; st = j;
            }
            else if(sess && str[j] == '0'){
                sess = 0;
                dx[st][st]++;
                dx[st][j]--;
                dx[j][st]--;
                dx[j][j]++;
            }
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=1; j<m; j++) {
            dx[i][j] += dx[i][j-1];
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=1; j<m; j++) {
            dx[j][i] += dx[j-1][i];
        }
    }
    int ret = 0;
    for (int i=0; i<m; i++) {
        for (int j=i; j<m; j++) {
            ret = max(ret,dx[i][j] * (j - i + 1));
        }
    }
    printf("%d",ret);
}