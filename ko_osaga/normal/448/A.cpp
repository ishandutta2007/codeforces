#include <cstdio>
int sumCup, sumMedal, n,t;
int main(){
    for (int i=0; i<3; i++) {
        scanf("%d",&t);
        sumCup += t;
    }
    for (int i=0; i<3; i++) {
        scanf("%d",&t);
        sumMedal += t;
    }
    scanf("%d",&n);
    int res = (sumCup + 4)/5 + (sumMedal + 9)/10;
    printf(res>n?"NO":"YES");
}