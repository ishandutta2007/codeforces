#include <cstdio>

using namespace std;

int n;
int in[205];

int rez[205];

int rep[105];
int repp[105];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n * 2; ++i){
        scanf("%d", in + i);
        ++rep[in[i]];
    }
    int inc = 0, cnt = 0;
    for (int i = 0; i < 100; ++i){
        if (rep[i] == 1) ++inc;
        if (rep[i] >= 2) ++cnt;
    }
    int c = 1, cc[3] = {0, 0, 0};
    for (int i = 0; i < n * 2; ++i){
        if (rep[in[i]] == 1){
           rez[i] = c;
           ++cc[c];
           c = 3 - c;
           continue;
        }
        if (repp[in[i]] == 0){
           rez[i] = 1;
           ++cc[1];
           ++repp[in[i]];
           continue;
        }
        if (repp[in[i]] == 1){
           rez[i] = 2;
           ++cc[2];
           ++repp[in[i]];
           continue;
        }
    }/*
    for (int i = 0; i < n * 2; ++i){
        printf("%d ", rez[i]);
    }
    printf("\n");*/
    for (int i = 0; i < n * 2; ++i){
        //printf("%d %d\n", cc[1], cc[2]);
        if (repp[in[i]] == 2 && rez[i] == 0){
           if (cc[1] < n){
              ++cc[1];
              rez[i] = 1;
           }
           else {
                ++cc[2];
                rez[i] = 2;
           }
        }
    }
    printf("%d\n", (inc / 2 + cnt) * (inc - inc / 2 + cnt));
    for (int i = 0; i < n * 2; ++i){
        printf("%d ", rez[i]);
    }
    printf("\n");
    return 0;
}