#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int P1[5005],P2[5005],PA[5005],C[5005],O[10005],Sz[5005],D[5005],Parent[5005];
int N,i,j,k,leaf,Inf[5005];
bool MozeNew[5005],MozeAll[5005];
bool MozeNew2[5005];

void ucitajisredi(){
    scanf("%d",&N);
    int i,j,k;
    for (i=1; i<N; i++){
        scanf("%d%d",&j,&k);
        P1[i]=j;
        P2[i]=k;
        C[j]++;
        C[k]++;
    }
    PA[1] = 1;
    for (i=2; i<=N+1; i++) PA[i] = PA[i-1] + C[i-1];
    memset(C,0,sizeof(C));
    for (i=1; i<N; i++){
        O[PA[P1[i]]+C[P1[i]]] = P2[i];
        C[P1[i]]++;
        O[PA[P2[i]]+C[P2[i]]] = P1[i];
        C[P2[i]]++;
    }
}

void dfs(int x,int odakle){
    int i;
    D[x]=1;
    Parent[x] = odakle;
    for (i=PA[x]; i<PA[x+1]; i++) if (O[i]!=odakle){
        dfs(O[i],x);
        D[x]+=D[O[i]];
    }
}

void ksack(){
    int i,j,k;
    //printf("%d\n",leaf);
    //for (i=1; i<=leaf; i++) printf("%d ",Inf[i]);
    //printf("\n");
    memset(MozeNew,0,sizeof(MozeNew));
    MozeNew[0]=true;
    for (i=1; i<=leaf; i++){
        memset(MozeNew2,0,sizeof(MozeNew2));
        for (j=Inf[i]; j<=N; j++){
            if (MozeNew[j-Inf[i]]) MozeNew2[j] = true;
        }
        for (j=1; j<=N; j++) MozeNew[j] = MozeNew[j] || MozeNew2[j];
    }
    for (i=1; i<=N; i++) MozeAll[i] = MozeAll[i] || MozeNew[i];
}

int main(){
    ucitajisredi();
    dfs(1,1);

    //for (i=1; i<=N; i++) printf("%d ",D[i]);
    //printf("\n");

    //root
    leaf=0;
    for (i=PA[1]; i<PA[2]; i++){
        leaf++;
        Inf[leaf] = D[O[i]];
    }
    ksack();
    for (i=2; i<=N; i++){
        leaf=0;
        for (j=PA[i]; j<PA[i+1]; j++){
            leaf++;
            if (O[j]==Parent[i]) Inf[leaf] = N-D[i]; else Inf[leaf] = D[O[j]];
        }
        ksack();
    }
    for (i=1; i<=N; i++) MozeAll[i] = MozeAll[i] || MozeAll[N-i-1];
    int ans=0;
    for (i=1; i<N-1; i++) if (MozeAll[i]) ans++;
    printf("%d\n",ans);
    for (i=1; i<N-1; i++){
        if (MozeAll[i]) printf("%d %d\n",i,N-i-1);
    }
    return 0;
}