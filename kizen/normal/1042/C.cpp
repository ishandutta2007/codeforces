#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4, INF = (int)2e9;
int N;
int arr[NS], chk[NS];

int main(){
    scanf("%d", &N);
    int f = 0;
    for(int i=1;i<=N;++i){
        scanf("%d", arr+i); if(!arr[i]) f = 1;
    }
    if(!f){
        int cnt = 0;
        for(int i=1;i<=N;++i) if(arr[i]<0) ++cnt;
        if((cnt&1)){
            int big = -INF, pos;
            for(int i=1;i<=N;++i) if(arr[i]<0&&arr[i]>big) big = arr[i], pos = i;
            printf("2 %d\n", pos), chk[pos] = 1;
        }
        int last = 1;
        while(chk[last]) ++last;
        for(int i=last+1;i<=N;++i) if(!chk[i]){
            printf("1 %d %d\n", last, i), last = i;
        }
    }
    else{
        int zl = 0, last = 1;
        while(arr[last]) ++last;
        for(int i=last+1;i<=N;++i) if(!arr[i]){
            chk[last] = chk[i] = 1;
            printf("1 %d %d\n", last, i), last = i;
        }
        zl = last;
        int cnt = 0;
        for(int i=1;i<=N;++i) if(!chk[i]&&arr[i]<0) ++cnt;
        if((cnt&1)){
            int big = -INF, pos;
            for(int i=1;i<=N;++i) if(!chk[i]&&arr[i]<0&&arr[i]>big) big = arr[i], pos = i;
            chk[zl] = chk[pos] = 1;
            if(pos>zl){
                printf("1 %d %d\n", zl, pos);
                for(int i=1;i<=N;++i) if(!chk[i]){
                    printf("2 %d\n", pos); break;
                }
            }
            else{
                printf("1 %d %d\n", pos, zl, zl);
                for(int i=1;i<=N;++i) if(!chk[i]){
                    printf("2 %d\n", zl); break;
                }
            }
        }
        else{
            chk[zl] = 1;
            for(int i=1;i<=N;++i) if(!chk[i]){
                printf("2 %d\n", zl); break;
            }
        }
        last = 1;
        while(chk[last]) ++last;
        for(int i=last+1;i<=N;++i) if(!chk[i]){
            printf("1 %d %d\n", last, i), last = i;
        }
    }
    return 0;
}