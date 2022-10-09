#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,n,m,i,j,k,l;
char posl,napotezu;

int isti,razl;

int x1,y1,x2,y2;

int main(){
    scanf("%d%d",&N,&M);
    //probamo prvo crvenu
    isti=0;
    razl=0;
    n = N-1;
    m = M;
    posl = 'C';
    napotezu = 'R';
    while (n+m > 0){
        if (m==0){
            if (posl == 'C') isti++; else razl++;
            posl = 'C';
            n--;
        } else
        if (n==0){
            if (posl == 'P') isti++; else razl++;
            posl = 'P';
            m--;
        } else {
            if (napotezu == 'R'){
                razl++;
                posl = 'C'+'P'-posl;
                if (posl=='C') n--; else m--;
            } else {
                isti++;
                if (posl=='C') n--; else m--;
            }
        }
        napotezu = 'R'+'I' - napotezu;
    }
    x1 = isti;
    y1 = razl;
    //sada prvo plavu
    isti=0;
    razl=0;
    n = N;
    m = M-1;
    posl = 'P';
    napotezu = 'R';
    while (n+m > 0){
        //printf("%d %d %d %d\n",n,m,isti,razl);
        if (m==0){
            if (posl == 'C') isti++; else razl++;
            posl = 'C';
            n--;
        } else
        if (n==0){
            if (posl == 'P') isti++; else razl++;
            posl = 'P';
            m--;
        } else {
            if (napotezu == 'R'){
                razl++;
                posl = 'C'+'P'-posl;
                if (posl=='C') n--; else m--;
            } else {
                isti++;
                if (posl=='C') n--; else m--;
            }
        }
        napotezu = 'R'+'I' - napotezu;
    }
    x2 = isti;
    y2 = razl;
    if (x1 > x2 || (x1==x2 && y1 < y2)) printf("%d %d\n",x1,y1); else printf("%d %d\n",x2,y2);
    return 0;
}