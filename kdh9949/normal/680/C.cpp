#include <cstdio>
#include <algorithm>
using namespace std;

int di[101];
char res[101];
int fp[11] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0};
int plist[11] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main(){
    for(int i = 2; i <= 10; i++){
        if(!fp[i]) continue;
        printf("%d\n", i);
        fflush(stdout);
        scanf("%s", res);
        if(res[0] == 'y') di[i]++;
    }
    for(int i = 2; i <= 7; i++){
        if(!fp[i]) continue;
        printf("%d\n", i * i);
        fflush(stdout);
        scanf("%s", res);
        if(res[0] == 'y'){
            puts("composite");
            fflush(stdout);
            return 0;
        }
    }
    int cnt = 0, idx;
    for(int i = 2; i <= 10; i++){
        if(di[i]) cnt++, idx = i;
    }
    if(cnt >= 2){
        puts("composite");
        fflush(stdout);
        return 0;
    }
    if(cnt == 0){
        puts("prime");
        fflush(stdout);
        return 0;
    }
    int t = idx;
    for(int i = 0; i < 11; i++){
        printf("%d\n", plist[i]);
        fflush(stdout);
        scanf("%s", res);
        if(res[0] == 'y'){
            puts("composite");
            fflush(stdout);
            return 0;
        }
    }
    puts("prime");
    fflush(stdout);
    return 0;
}