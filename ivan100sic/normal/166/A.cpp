#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct tim{
    int task,pen;
};

tim A[1000];
int N,i,j,k;

bool cmp(tim a,tim b){
    return a.task > b.task || (a.task == b.task && a.pen < b.pen);
}

int Rank[1000],sol;

int main(){
    scanf("%d%d",&N,&k);
    for (i=1; i<=N; i++){
        scanf("%d%d",&A[i].task,&A[i].pen);
    }
    sort(A+1,A+N+1,cmp);
    for (i=1; i<=N; i++){
        if (i>1 && (A[i].task == A[i-1].task && A[i].pen == A[i-1].pen)){
            Rank[i] = Rank[i-1];
        } else {
            Rank[i] = i;
        }
    }
    //for (i=1; i<=N; i++) printf("%d %d\n",i,Rank[i]);
    k = Rank[k];
    for (i=1; i<=N; i++) if (Rank[i]==k) sol++;
    printf("%d\n",sol);
    return 0;
}