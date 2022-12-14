#include <bits/stdc++.h>
using namespace std;

const int NS = 2*(1e5)+4;
int N;
vector < int > arr[NS];
int arrN[NS], hap[NS];
map < int, int > can;

int main(){
    scanf("%d", &N);
    int i, j, in, x, y;
    for(i=1;i<=N;i++){
        scanf("%d", arrN+i);
        for(j=0;j<arrN[i];j++){
            scanf("%d", &in);
            arr[i].push_back(in); hap[i]+=in;
        }
        for(j=0;j<arrN[i];j++) can[hap[i]-arr[i][j]]++;
    }
    int f = 0;
    for(i=1;i<=N;i++){
        for(j=0;j<arrN[i];j++) can[hap[i]-arr[i][j]]--;
        for(j=0;j<arrN[i];j++) if(can[hap[i]-arr[i][j]]){
            f = 1; break;
        }
        if(f) break;
        for(j=0;j<arrN[i];j++) can[hap[i]-arr[i][j]]++;
    }
    if(!f) puts("NO");
    else{
        puts("YES");
        f = 0;
        for(x=1;x<=N;x++){
            if(x==i) continue;
            for(y=0;y<arrN[x];y++) if(hap[x]-arr[x][y]==hap[i]-arr[i][j]){
                f = 1; break;
            }
            if(f) break;
        }
        printf("%d %d\n%d %d", i, j+1, x, y+1);
    }

    return 0;
}