#include <cstdio>

using namespace std;

int n, t;
char niz[1005];

int main(){
    scanf("%d%d%s", &n, &t, niz);
    //int poin = 0;
    for (int i = 0; i < t; ++i){
        //++poin;
        for (int i = 1; i < n; ++i){
            if (niz[i] == 'G' && niz[i - 1] == 'B'){
               niz[i] = 'B';
               niz[i - 1] = 'G';
               ++i;
            }
        }
    }/*
    for (int i = poin; poin < n; ++i){
        printf("%c", niz[i]);
    }*/
    printf("%s\n", niz);
    return 0;
}