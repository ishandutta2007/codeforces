#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,i,j;
double A[105],S[105],P[105],best;

int main(){
    scanf("%d",&N);
    P[0] = 1;
    for (i=1; i<=N; i++){
        scanf("%lf",A+i);
        if (A[i]==1){
            printf("1\n");
            return 0;
        }
    }
    sort(A+1,A+N+1);
    for (i=1; i<=N; i++){
        S[i] = S[i-1] + A[i] / (1-A[i]);
        P[i] = P[i-1] * (1 - A[i]);
    }
    //kombinovano
    for (i=1; i<=N; i++){
        for (j=i+2; j<=N; j++){
            best = max(best , (S[i] + S[N] - S[j-1])*P[i]*P[N]/P[j-1]);
        }
    }
    //prefiks
    for (i=1; i<=N; i++) best = max(best, S[i]*P[i]);
    //sufiks
    for (i=1; i<=N-1; i++) best = max(best, (S[N] - S[i])*P[N]/P[i]);
    printf("%.14lf\n",best);
    return 0;
}