#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

map <pair<int,int> , bool> Ex;
map <pair<int,int> , int> D;

int N,X0,Y0,Xe,Ye,T;
int Qx[1000005],Qy[1000005],qs,qe,newpts;

void ucitajisredi(){
    scanf("%d%d%d%d%d",&X0,&Y0,&Xe,&Ye,&N);
    int i,j,k,l,m;
    for (i=1; i<=N; i++){
        scanf("%d%d%d",&j,&k,&l);
        for (m=k; m<=l; m++){
            Ex[make_pair(j,m)] = true;
            D[make_pair(j,m)] = -1;
        }
    }
}

pair <int,int> PP;

void obidji(int x,int y){
    PP = make_pair(x,y);
    if (Ex[PP] == false) return;
    if (D[PP] != -1) return;
    D[PP] = T;
    newpts++;
    Qx[qe+newpts] = x;
    Qy[qe+newpts] = y;
}


void bfs(){
    Qx[1] = X0;
    Qy[1] = Y0;
    qs=1;
    qe=1;
    newpts=1;
    int i,j,k,l;
    while (newpts>0){
        newpts=0;
        T++;
        for (i=qs; i<=qe; i++){
            obidji(Qx[i]+1,Qy[i]+1);
            obidji(Qx[i]+1,Qy[i]);
            obidji(Qx[i]+1,Qy[i]-1);
            obidji(Qx[i],Qy[i]+1);
            obidji(Qx[i],Qy[i]-1);
            obidji(Qx[i]-1,Qy[i]+1);
            obidji(Qx[i]-1,Qy[i]);
            obidji(Qx[i]-1,Qy[i]-1);
        }
        qs = qe+1;
        qe += newpts;
    }
}

int main(){
    ucitajisredi();
    bfs();
    PP = make_pair(Xe,Ye);
    printf("%d\n",D[PP]);
    return 0;
}