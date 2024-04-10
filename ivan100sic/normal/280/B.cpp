#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[100005],N;
int highbit,P[100005],PPP,i,j,k,l,sol,mx,it;

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    while (true){
        highbit = -1;
        for (i=1; i<=N; i++){
            for (j=30; j>=0; j--) if (A[i] & (1<<j)){
                if (j>highbit) highbit = j;
                break;
            }
        }
        for (i=1; i<=N; i++) if ((A[i] & (1<<highbit))==0) goto fuck;
        for (i=1; i<=N; i++) A[i]-=(1<<highbit);
    }
    fuck:
    for (i=1; i<=N; i++){
        if (A[i] & (1<<highbit)){
            PPP++;
            P[PPP] = i;
        }
    }
    P[0] = 0;
    P[PPP+1] = N+1;
    for (i=1; i<=PPP; i++){
        mx=0;
        //levo
        for (j=P[i]+1; j<P[i+1]; j++){
            mx = max(mx,A[j]);
            sol = max(sol,A[P[i]] ^ mx);
        }
        //desno
        mx=0;
        for (j=P[i]-1; j>P[i-1]; j--){
            mx = max(mx,A[j]);
            sol = max(sol,A[P[i]] ^ mx);
        }
    }
    printf("%d\n",sol);
    return 0;
}