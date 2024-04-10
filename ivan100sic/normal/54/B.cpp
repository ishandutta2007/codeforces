#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[25][25],Tmp[25][25];
char Svi[1000][25][25],pcs;
int N,A,B,w,h,sol,hopt=1000,wopt=1000;

void ucitaj(){
    int i;
    scanf("%d%d",&A,&B);
    for (i=1; i<=A; i++){
        scanf("%s",S[i]+1);
    }
}

void rotiraj(int a){
    int i,j,k;
    for (i=1; i<=w; i++){
        for (j=1; j<=w; j++){
            Tmp[i][j] = Svi[a][j][w-i+1];
        }
    }
    memcpy(Svi[a],Tmp,sizeof(Tmp));
}

bool identicni(int l,int r){
    int i,j,k;
    for (i=1; i<=w; i++){
        for (j=1; j<=w; j++){
            if (Svi[l][i][j]!=Svi[r][i][j]) return false;
        }
    }
    return true;
}

bool jednakikv(int l,int r){
    bool moze=false;
    rotiraj(l);
    moze = moze || identicni(l,r);
    rotiraj(l);
    moze = moze || identicni(l,r);
    rotiraj(l);
    moze = moze || identicni(l,r);
    rotiraj(l);
    moze = moze || identicni(l,r);
    return moze;
}

bool jednakiprg(int l,int r){
    int i,j,k;
    bool ovako,rotirano;
    ovako=true;
    rotirano=true;
    for (i=1; i<=w; i++){
        for (j=1; j<=h; j++){
            if (Svi[l][i][j] != Svi[r][i][j]) ovako=false;
            if (Svi[l][i][j] != Svi[r][w-i+1][h-j+1]) rotirano=false;
        }
    }
    return ovako || rotirano;
}

bool jednaki(int l,int r){
    if (w==h) return jednakikv(l,r); else return jednakiprg(l,r);
}

int resi(){
    int pcs = 0,rez = 1,i,j,k,l;
    for (i=0; i<A/w; i++){
        for (j=0; j<B/h; j++){
            pcs++;
            for (k=1; k<=w; k++){
                for (l=1; l<=h; l++){
                    Svi[pcs][k][l] = S[w*i+k][h*j+l];
                }
            }
        }
    }
    for (i=1; i<pcs; i++){
        for (j=i+1; j<=pcs; j++){
            if (jednaki(i,j)) rez=0;
        }
    }
    //printf("%d %d %d\n",w,h,rez);
    return rez;
}

int main(){
    ucitaj();
    for (w=1; w<=A; w++){
        for (h=1; h<=B; h++){
            if (A%w + B%h == 0) if (resi()==1){
                sol++;
                if (w*h < wopt*hopt || (w*h == wopt*hopt && w<wopt)){
                    hopt = h;
                    wopt = w;
                }
            }
        }
    }
    printf("%d\n%d %d\n",sol,wopt,hopt);
    return 0;
}