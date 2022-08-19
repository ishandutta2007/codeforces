#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

int dx[100005][30];

int n, q, s[100005], e[100005], x[100005];

int main(){
    scanf("%d %d",&n,&q);
    for(int i=0; i<q; i++){
        scanf("%d %d %d",&s[i],&e[i],&x[i]);
        for(int j=0; j<30; j++){
            if((x[i] >> j ) & 1){
                dx[s[i]][j]++;
                dx[e[i]+1][j]--;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<30; j++){
            dx[i][j] += dx[i-1][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<30; j++){
            dx[i][j] = min(dx[i][j],1);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<30; j++){
            dx[i][j] += dx[i-1][j];
        }
    }
    for(int i=0; i<q; i++){
        int ret = 0;
        for(int j=0; j<30; j++){
            int bad = dx[e[i]][j] - dx[s[i]-1][j];
            if(bad == e[i] - s[i] + 1 && ((x[i] >> j) & 1)){
                continue;
            }
            else if(bad != e[i] - s[i] + 1 && (((x[i] >> j) & 1) == 0)){
                continue;
            }
            else{
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for(int i=1; i<=n; i++){
        int ret = 0;
        for(int j=0; j<30; j++){
            if(dx[i][j] != dx[i-1][j]) ret |= (1<<j);
        }
        printf("%d ",ret);
    }
}