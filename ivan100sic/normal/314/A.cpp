#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long A[200005],D[200005];
int N,i,j,k,l,K,podiz;
long long kor;

int main(){
    scanf("%d%d",&N,&K);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    for (i=1; i<N; i++) D[i+1] = D[i] + A[i] * (i-1);
    for (i=1; i<=N; i++) D[i] -= A[i]*(i-1)*(N-i);
    for (i=1; i<=N; i++){
        D[i] += kor + A[i]*(N-i)*podiz;
        //printf("%d %lld\n",i,D[i]);
        if (D[i] < K){
            //treba ga obrisati sa rang liste
            //svaki sledeci koji nije obrisan sa liste
            //podize se za jedno mesto
            podiz++;
            printf("%d\n",i);
            kor -= A[i]*(i-1);
        } else {
            //rekalkulisemo korekciju
            kor -= A[i]*podiz;
        }
    }
    return 0;
}