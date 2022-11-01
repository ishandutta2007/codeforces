#include <cstdio>

using namespace std;

char in[1000005];
int len;

char out[1000005];

bool att(){
     int pom = 0;
     for (int i = 0; i < len; ++i){
         pom = (pom * 10 + (out[i] - '0')) % 7;
     }
     return (pom == 0);
}

int main(){
    scanf("%s", in);
    while (in[++len] != '\0');
    int p1, p6, p8, p9;
    for (int i = 0; i < len; ++i){
        if (in[i] == '1') p1 = i;
        if (in[i] == '6') p6 = i;
        if (in[i] == '8') p8 = i;
        if (in[i] == '9') p9 = i;
    }
    
    int poin = 0, c0 = 0;
    for (int i = 0; i < len; ++i){
        if (i == p1) continue;
        if (i == p6) continue;
        if (i == p8) continue;
        if (i == p9) continue;
        if (in[i] == '0'){++c0; continue;}
        out[poin++] = in[i];
    }
    
    int niz[5] = {poin, poin + 1, poin + 2, poin + 3, 0};
    
    for (int i = 0; i < c0; ++i){
        out[len - 1 - i] = '0';
    }
    
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            if (i == j) continue;
            for (int k = 0; k < 4; ++k){
                if (k == i || k == j) continue;
                int l = 3 + 2 + 1 + 0 - i - k - j;
                out[niz[i]] = '1';
                out[niz[j]] = '6';
                out[niz[k]] = '8';
                out[niz[l]] = '9';
                if (att()){
                   out[len] = '\0';
                   printf(out);
                   printf("\n");
                   return 0;
                }
            }
        }
    }
    printf("0\n");
    return 0;
}