#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int P1[10005],P2[10005],PA[10005],C[10005],O[10005],N,M;

void ucitajisredi(){
    int i;
    scanf("%d%d",&N,&M);
    for (i=1; i<=M; i++){
        scanf("%d%d",P1+i,P2+i);
        C[P1[i]]++;
        C[P2[i]]++;
    }
    PA[1] = 1;
    for (i=2; i<=N+1; i++) PA[i] = PA[i-1] + C[i-1];
    memset(C,0,sizeof(C));
    for (i=1; i<=M; i++){
        O[PA[P1[i]]+C[P1[i]]] = P2[i];
        O[PA[P2[i]]+C[P2[i]]] = P1[i];
        C[P1[i]]++;
        C[P2[i]]++;
    }
}

vector <int> Tim[10005],jedan,dva;
vector <int> Tim2[10005],Tim1[10005];
int TTT,T2,T1;
bool V[10005];

void dfs(int x){
    if (V[x]) return;
    V[x] = true;
    Tim[TTT].push_back(x);
    int i;
    for (i=PA[x]; i<PA[x+1]; i++){
        dfs(O[i]);
    }
}

vector <int> zbir(vector <int> a,vector <int> b){
    int i;
    for (i=0; i<b.size(); i++) a.push_back(b[i]);
    return a;
}

int main(){
    ucitajisredi();
    int i;
    for (i=1; i<=N; i++){
        if (!V[i]){
            TTT++;
            dfs(i);
        }
    }
    for (i=1; i<=TTT; i++) if (Tim[i].size() > 3){
        printf("-1\n");
        return 0;
    }
    for (i=1; i<=TTT; i++){
        if (Tim[i].size() == 2){
            T2++;
            Tim2[T2] = Tim[i];
        } else
        if (Tim[i].size() == 1){
            T1++;
            Tim1[T1] = Tim[i];
        }
    }
    if (T2>T1){
        printf("-1\n");
        return 0;
    }
    for (i=1; i<=TTT; i++){
        if (Tim[i].size() == 3){
            printf("%d %d %d\n",Tim[i][0],Tim[i][1],Tim[i][2]);
        }
    }
    if (T2>T1){
        printf("-1\n");
        return 0;
    }
    for (i=1; i<=T2; i++){
        Tim2[i] = zbir(Tim2[i] , Tim1[i]);
        printf("%d %d %d\n",Tim2[i][0],Tim2[i][1],Tim2[i][2]);
    }
    for (i=T2+1; i<=T1; i+=3){
        Tim[i] = zbir(zbir(Tim1[i],Tim1[i+1]),Tim1[i+2]);
        printf("%d %d %d\n",Tim[i][0],Tim[i][1],Tim[i][2]);
    }
    return 0;
}