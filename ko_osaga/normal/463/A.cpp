#include <cstdio>

int n,s;
int dol[105],cen[105];
int maxSweet = -1;

int calc(int p){
    if(p == 0) return 0;
    else return 100 - p;
}

int main(){
    scanf("%d %d",&n,&s);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&dol[i],&cen[i]);
        if(dol[i] < s){
            if(maxSweet < calc(cen[i])){
                maxSweet = calc(cen[i]);
            }
        }
        else if(dol[i] == s && cen[i] == 0 && maxSweet == -1){
            maxSweet = 0;
        }
    }
    printf("%d",maxSweet);
}