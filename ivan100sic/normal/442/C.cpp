#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node{
    node *lev,*des;
    int vr;
};

struct brs{
    node *pt;
    int vr;
    inline friend bool operator <(brs a,brs b){
        return a.vr < b.vr;
    }
};

int reduk,rprh,N,i,j;
int A[1000005];
node B[1000005];
brs Z[1000005];
node *curr;
long long sol;

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    for (i=1; i<=N; i++){
        B[i].vr = A[i];
        B[i].lev = B+i-1;
        B[i].des = B+i+1;
        Z[i].vr = A[i];
        Z[i].pt = B+i;
    }
    sort(Z+1,Z+N+1);
    for (i=1; i<=N-2; i++){
        reduk = Z[i].vr;
        rprh = Z[i-1].vr;
        //printf("%d %d\n",N-1-i,reduk-rprh);
        sol += (N-1ll-i)*(reduk-rprh);
        curr = Z[i].pt;
        if (curr->lev != B && curr->des != B+N+1){
            //printf("%d %d minus %d\n",curr->lev->vr,curr->des->vr,reduk);
            sol += min(curr->lev->vr , curr->des->vr) - reduk;
        }
        //izbacivanje
        curr->lev->des = curr->des;
        curr->des->lev = curr->lev;
    }
    printf("%lld\n",sol);
    return 0;
}