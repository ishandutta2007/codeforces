#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

int A,B;

double l1,l2,l3,l4;

int kv(int x){
    return x*x;
}

int aps(int x){
    if (x<0) return -x;
    return x;
}

double len(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    double r = 0;
    r += sqrt(kv(x1-x2)+kv(y1-y2));
    r += sqrt(kv(x2-x3)+kv(y2-y3));
    r += sqrt(kv(x3-x4)+kv(y3-y4));
    return r;
}

void ispisi(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    printf("%d %d\n",x1,y1);
    printf("%d %d\n",x2,y2);
    printf("%d %d\n",x3,y3);
    printf("%d %d\n",x4,y4);
}

int dist(int x1,int y1,int x2,int y2){
    return aps(x1-x2) + aps(y1-y2);
}

int X[1005],Y[1005],N;

void admissible(){
    int i,j;
    for (i=0; i<=A; i++){
        for (j=0; j<=B; j++){
            if (dist(i,j,0,0) <= 5 || dist(i,j,A,0) <= 5 || dist(i,j,0,B) <= 5 || dist(i,j,A,B) <= 5){
                N++;
                X[N] = i;
                Y[N] = j;
            }
        }
    }
}

bool ok(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    return (dist(x1,y1,x2,y2) > 0 &&
            dist(x1,y1,x3,y3) > 0 &&
            dist(x1,y1,x4,y4) > 0 &&
            dist(x2,y2,x3,y3) > 0 &&
            dist(x2,y2,x4,y4) > 0 &&
            dist(x3,y3,x4,y4) > 0);
}

void resi(){
    double opt = -1,curr;
    int i,j,k,l,x1,y1,x2,y2,x3,y3,x4,y4;
    for (i=1; i<=N; i++){
        for (j=1; j<=N; j++){
            for (k=1; k<=N; k++){
                for (l=1; l<=N; l++){
                    if (ok(X[i],Y[i],X[j],Y[j],X[k],Y[k],X[l],Y[l])){
                        curr = len(X[i],Y[i],X[j],Y[j],X[k],Y[k],X[l],Y[l]);
                        if (curr > opt){
                            opt = curr;
                            x1 = X[i];
                            x2 = X[j];
                            x3 = X[k];
                            x4 = X[l];

                            y1 = Y[i];
                            y2 = Y[j];
                            y3 = Y[k];
                            y4 = Y[l];
                        }
                    }
                }
            }
        }
    }
    ispisi(x1,y1,x2,y2,x3,y3,x4,y4);
}



int main(){
    scanf("%d%d",&A,&B);
    admissible();
    resi();
    return 0;
}