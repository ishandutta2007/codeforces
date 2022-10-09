#include <cstdio>
#include <cstring>
#include <algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

char A[100][100];
int Idx[100][100],Low[100][100];
int N,M,i,j,k,l,indeks,num;
int rootx,rooty;
bool cutfound;

void cutvertex(int x,int y,int prex,int prey){
    bool isroot;
    isroot = (x==rootx && y==rooty);
    int chld=0;
    indeks++;
    Idx[x][y] = indeks;
    Low[x][y] = indeks;
    //recimo ocemo da posetimo x+1,y
    if (A[x+1][y] == '#'){
        if (Idx[x+1][y] != 0){
            if (x+1!=prex || y!=prey) Low[x][y] = min(Low[x][y],Idx[x+1][y]);
        } else {
            cutvertex(x+1,y,x,y);
            Low[x][y] = min(Low[x][y],Low[x+1][y]);
            if (Low[x+1][y] >= Idx[x][y] && !isroot) cutfound=true;
            chld++;
        }
    }
    if (A[x-1][y] == '#'){
        if (Idx[x-1][y] != 0){
            if (x-1!=prex || y!=prey) Low[x][y] = min(Low[x][y],Idx[x-1][y]);
        } else {
            cutvertex(x-1,y,x,y);
            Low[x][y] = min(Low[x][y],Low[x-1][y]);
            if (Low[x-1][y] >= Idx[x][y] && !isroot) cutfound=true;
            chld++;
        }
    }
    if (A[x][y+1] == '#'){
        if (Idx[x][y+1] != 0){
            if (x!=prex || y+1!=prey) Low[x][y] = min(Low[x][y],Idx[x][y+1]);
        } else {
            cutvertex(x,y+1,x,y);
            Low[x][y] = min(Low[x][y],Low[x][y+1]);
            if (Low[x][y+1] >= Idx[x][y] && !isroot) cutfound=true;
            chld++;
        }
    }
    if (A[x][y-1] == '#'){
        if (Idx[x][y-1] != 0){
            if (x!=prex || y-1!=prey) Low[x][y] = min(Low[x][y],Idx[x][y-1]);
        } else {
            cutvertex(x,y-1,x,y);
            Low[x][y] = min(Low[x][y],Low[x][y-1]);
            if (Low[x][y-1] >= Idx[x][y] && !isroot) cutfound=true;
            chld++;
        }
    }
    //printf("%d %d %d\n",x,y,chld);
    //bool stari=cutfound;
    if (isroot && chld>=2) cutfound=true;
    //if (stari==false && cutfound==true) printf("cut at %d %d\n",x,y);
}

void debug(){
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++) printf("%d ",Idx[i][j]);
        puts("");
    }
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++) printf("%d ",Low[i][j]);
        puts("");
    }
}

void ucitaj(){
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++){
        scanf("%s",A[i]+1);
    }
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            if (A[i][j]=='#'){
                rootx=i;
                rooty=j;
                num++;
            }
        }
    }
}

int main(){
    ucitaj();
    cutvertex(rootx,rooty,rootx,rooty);
    //debug();
    if (num<=2) printf("-1\n"); else
    if (cutfound) printf("1\n"); else printf("2\n");
    return 0;
}