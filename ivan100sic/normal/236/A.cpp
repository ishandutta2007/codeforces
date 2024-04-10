#include <cstdio>

int Cnt[256];
char S[256];
int i,j;

int main(){
    scanf("%s",S+1);
    for (i=1; S[i]; i++){
        if (Cnt[S[i]]==0){
            Cnt[S[i]]=1;
            j++;
        }
    }
    if (j%2 == 0) printf("CHAT WITH HER!\n"); else printf("IGNORE HIM!\n");
    return 0;
}