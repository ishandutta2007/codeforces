#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,i,j,k,w;
int W[505];
double opt;

int main(){
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++) scanf("%d",W+i);
    for (i=1; i<=M; i++){
        scanf("%d%d%d",&j,&k,&w);
        opt = max(opt,(1.0*(W[j]+W[k]))/w);
    }
    printf("%.11lf\n",opt);
    return 0;
}