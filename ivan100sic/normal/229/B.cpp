#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 131072
#define OFFS 131071
using namespace std;

vector <int> Sus[100005],Dis[100005],Vremena[100005],Sledece[100005];
int D[MAXN],N,M;
vector <int>::iterator it;

void ucitajisredi(){
    scanf("%d%d",&N,&M);
    int i,j,k,w,nn;
    for (i=1; i<=M; i++){
        scanf("%d%d%d",&j,&k,&w);
        Sus[j].push_back(k);
        Sus[k].push_back(j);
        Dis[j].push_back(w);
        Dis[k].push_back(w);
    }
    for (i=1; i<=N; i++){
        scanf("%d",&nn);
        for (j=1; j<=nn; j++){
            scanf("%d",&k);
            Vremena[i].push_back(k);
        }
        if (nn==0) continue;
        Sledece[i].resize(nn);
        Sledece[i][nn-1] = Vremena[i][nn-1];
        for (j=nn-2; j>=0; j--){
            if (Vremena[i][j] == Vremena[i][j+1]-1){
                Sledece[i][j] = Sledece[i][j+1];
            } else {
                Sledece[i][j] = Vremena[i][j];
            }
        }
    }
}

int Heap[2*MAXN];
bool V[MAXN];

int boljicvor(int a,int b){
    if (V[a] && V[b]) return 0;
    if (!V[a] && V[b]) return a;
    if (V[a] && !V[b]) return b;
    if (D[a] < D[b]) return a; else return b;
}

void update(int x){
    x+=OFFS;
    while (x>1){
        x/=2;
        Heap[x] = boljicvor(Heap[2*x],Heap[2*x+1]);
    }
}

int sledecevreme(int planeta,int t){
    int l,r,m,o;
    l=0;
    r=Vremena[planeta].size()-1;
    o=-1;
    while (l<=r){
        m = (l+r)/2;
        if (Vremena[planeta][m] < t){
            l = m+1;
        } else
        if (Vremena[planeta][m] > t){
            r = m-1;
        } else{
            o=m;
            break;
        }
    }
    if (o==-1) return t; else return Sledece[planeta][o]+1;
}

int main(){
    ucitajisredi();
    int x,i,j,k;
    for (i=1; i<=N; i++) Heap[i+OFFS] = i;
    x=1;
    memset(D,63,sizeof(D));
    D[1] = 0;
    while (true){
        V[x] = true;
        update(x);
        for (i=0; i<Sus[x].size(); i++){
            j = Sus[x][i];
            k = Dis[x][i];
            if (sledecevreme(x,D[x]) + k < D[j]){
                D[j] = sledecevreme(x,D[x]) + k;
                update(j);
            }
        }
        x = Heap[1];
        if (x==0) break;
    }
    if (D[N] > 1050000000) D[N] = -1;
    printf("%d\n",D[N]);
    return 0;
}