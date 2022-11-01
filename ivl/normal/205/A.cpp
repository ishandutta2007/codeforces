#include <cstdio>

using namespace std;

int n;
int niz[100005];
int coor[100005];
int pok;

int main(){
    scanf("%d", &n);
    scanf("%d", niz);
    coor[0] = 0;
    ++pok;
    for (int i = 1; i < n; ++i){
        scanf("%d", niz + i);
        if (niz[i] < niz[coor[0]]){
           coor[0] = i;
           pok = 1;
           continue;
        }
        if (niz[i] == niz[coor[0]]){
           coor[pok++] = i;
        }
    }
    if (pok > 1){
       printf("Still Rozdil\n");
    }
    else {
         printf("%d\n", coor[0] + 1);
    }
    return 0;
}