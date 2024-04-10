#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char A[2000005],B[2000005];
int prvi,drugi,zajedni,N,i,r1,r2,napotezu;

int main(){
    scanf("%d%s%s",&N,A+1,B+1);
    N*=2;
    for (i=1; i<=N; i++){
        if (A[i]=='1' && B[i]=='1') zajedni++; else
        if (A[i]=='1') prvi++; else
        if (B[i]=='1') drugi++;
    }
    napotezu = 1;
    while (prvi+drugi+zajedni>0){
        if (napotezu==1){
            if (zajedni>0){
                zajedni--;
                r1++;
            } else
            if (prvi>0){
                prvi--;
                r1++;
            } else
            if (drugi>0){
                drugi--;
            }
        } else
        if (napotezu==2){
            if (zajedni>0){
                zajedni--;
                r2++;
            } else
            if (drugi>0){
                drugi--;
                r2++;
            } else
            if (prvi>0){
                prvi--;
            }
        }
        napotezu = 3-napotezu;
    }
    if (r1>r2) printf("First\n"); else
    if (r1<r2) printf("Second\n"); else printf("Draw\n");
    return 0;
}