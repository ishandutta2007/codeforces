#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct box{
    int k,br;
};

int N,i,j,sol;
long long k;
box A[100005];

int main(){
    int i,j;
    scanf("%d",&N);
    for (i=1; i<=N; i++){
        scanf("%d%d",&A[i].k,&A[i].br);
    }
    for (i=1; i<=N; i++){
        k=1;
        j=0;
        while (k < A[i].br){
            k *= 4;
            j++;
        }
        if (A[i].br == 1) j=1;
        sol = max(sol,j + A[i].k);
    }
    printf("%d\n",sol);
    return 0;
}