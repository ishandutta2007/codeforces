#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int P1[100005],P2[100005],PA[100005],C[100005],O[200005],In[100005],Out[100005],D[100005],P[100005][22];
int A[200005],N,Q,Root[100005],R,M,QA[100005],Vreme,Ku[100005];

struct upit{
    int id,x,sta;
    bool end;
};

upit Z[200005];

void ucitajisredi(){
    scanf("%d",&N);
    int i,j,k,l;
    for (i=1; i<=N; i++){
        scanf("%d",&k);
        if (k==0){
            R++;
            Root[R]=i;
        } else {
            M++;
            P1[M] = i;
            P2[M] = k;
            C[i]++;
            C[k]++;
        }
    }
    PA[1] = 1;
    for (i=2; i<=N+1; i++) PA[i] = PA[i-1] + C[i-1];
    memset(C,0,sizeof(C));
    for (i=1; i<=M; i++){
        O[C[P1[i]]+PA[P1[i]]] = P2[i];
        C[P1[i]]++;
        O[C[P2[i]]+PA[P2[i]]] = P1[i];
        C[P2[i]]++;
    }
}

void dfs(int x,int odakle){
    Vreme++;
    In[x] = Vreme;
    P[x][0] = odakle;
    int i;
    for (i=PA[x]; i<PA[x+1]; i++) if (O[i]!=odakle) {
        D[O[i]] = D[x]+1;
        dfs(O[i],x);
    }
    Vreme++;
    Out[x] = Vreme;
}

void parentize(){
    int i,j;
    for (j=1; j<=20; j++){
        for (i=1; i<=N; i++) P[i][j] = P[P[i][j-1]][j-1];
    }
}

int xticale(int v,int x){
    int j;
    for (j=20; j>=0; j--){
        if (x>=(1<<j)){
            v = P[v][j];
            x-=(1<<j);
        }
    }
    return v;
}

bool cmp(upit a,upit b){
    return a.x < b.x;
}

void readqs(){
    scanf("%d",&Q);
    int i,j,k;
    for (i=1; i<=Q; i++){
        scanf("%d%d",&j,&k);
        j = xticale(j,k);
        if (j!=0){
            Z[2*i-1].x = In[j]-1;
            Z[2*i-1].id = i;
            Z[2*i-1].end = false;
            Z[2*i-1].sta = D[j]+k;
            Z[2*i].x = Out[j];
            Z[2*i].id = i;
            Z[2*i].end = true;
            Z[2*i].sta = D[j]+k;
        }
    }
    sort(Z+1,Z+2*Q+1,cmp);
}

void ansqs(){
    int i,j,k,l,m;
    j=0;
    for (i=1; i<=N; i++){
        A[In[i]] = D[i];
    }
    for (i=1; i<=2*N; i++){
        Ku[A[i]]++;
        while (Z[j+1].x <= i && j<2*Q){
            j++;
            if (Z[j].x == i){
                if (Z[j].end) QA[Z[j].id] += Ku[Z[j].sta];
                else QA[Z[j].id] -= Ku[Z[j].sta];
                //printf("%d %d\n",j,Ku[Z[j].sta]);
            }
        }
    }
}

void debug(){
    int i,j;
    for (i=1; i<=2*Q; i++) printf("%d %d %d %d\n",Z[i].id,Z[i].x,Z[i].sta,Z[i].end);
    for (i=1; i<=2*N; i++) printf("%d %d\n",i,A[i]);
}

int main(){
    ucitajisredi();
    int i,j,k,l;
    for (i=1; i<=R; i++){
        P[Root[i]][0] = 0;
        D[Root[i]] = 1;
        dfs(Root[i],0);
    }
    parentize();
    readqs();
    ansqs();
    //debug();
    for (i=1; i<=Q; i++){
        QA[i]--;
        if (QA[i]<0) QA[i]=0;
        printf("%d ",QA[i]);
    }
    return 0;
}