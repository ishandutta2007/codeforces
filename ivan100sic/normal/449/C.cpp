#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int C[100005];

void sito(){
    int i,j,k;
    j = 2;
    for (i=1; i<=100; i++){
        while (C[j]>0) j++;
        for (k=j*j; k<=100000; k+=j) if (C[k]==0) C[k] = j;
        j++;
    }
    for (i=1; i<=100000; i++) if (C[i]==0) C[i] = i;
}

bool V[100005];
int L[100005],LLL;

int X[100005],Y[100005],Z;

int main(){
    sito();
    int i,j,k,l,w,n;
    scanf("%d",&n);
    for (i=100000; i>=2; i--) if (C[i]==i){
        LLL = 0;
        for (j=i; j<=n; j+=i){
            if (!V[j]){
                LLL++;
                L[LLL] = j/i;
            }
        }
        if (LLL % 2 == 0){
            for (j=1; j<=LLL; j+=2){
                Z++;
                X[Z] = L[j] * i;
                Y[Z] = L[j+1] * i;
                V[X[Z]] = true;
                V[Y[Z]] = true;
            }
        } else {
            for (k=1; k<=LLL; k++) if (C[L[k]] > 1 && C[L[k]] < i) break;
            w = 0;
            for (l=1; l<=LLL; l++) if (l!=k){
                if (w==0){
                    w = L[l];
                } else {
                    Z++;
                    X[Z] = w*i;
                    Y[Z] = L[l] * i;
                    V[X[Z]] = true;
                    V[Y[Z]] = true;
                    w = 0;
                }
            }
        }
    }
    printf("%d\n",Z);
    for (i=1; i<=Z; i++) printf("%d %d\n",X[i],Y[i]);
    return 0;
}