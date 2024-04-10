#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct mirror{
    int l,r,score;
    bool ceil;
};

struct hitpt{
    double x;
    bool ceil;
};

mirror A[105];
hitpt H[1005];
int HHH;

int N,h1,h2;

void ucitaj(){
    scanf("%d%d%d",&h1,&h2,&N);
    char c;
    int i;
    for (i=1; i<=N; i++){
        scanf("%d %c%d%d",&A[i].score,&c,&A[i].l,&A[i].r);
        if (c=='T') A[i].ceil = true;
    }
}

//zrak na gore

void pushhitpt(double x,bool ceil){
    HHH++;
    H[HHH].x = x;
    H[HHH].ceil = ceil;
}

void makehitpt_up(int tgt){
    int i,j,k,l;
    double x;
    bool cl=true;
    //prava m=tgt-h1
    //y = m/100k
    HHH=0;
    for (i=100; i<tgt; i+=100){
        x = 100000.0*(i-h1) / (tgt-h1);
        pushhitpt(x , cl);
        cl = !cl;
    }
}

void makehitpt_dn(int tgt){
    int i,j,k,l;
    double x;
    bool cl=false;
    //prava m=tgt-h1
    //y = m/100k
    HHH=0;
    for (i=0; i>tgt; i-=100){
        x = 100000.0*(i-h1) / (tgt-h1);
        pushhitpt(x , cl);
        //printf("push %.2lf %c\n",x,cl+48);
        cl = !cl;
    }
}

bool DontUseMeAgain[105];

int findmirror(hitpt b){
    int i,r;
    for (i=1; i<=N; i++){
        if (A[i].l <= b.x && b.x <= A[i].r && b.ceil == A[i].ceil){
            if (DontUseMeAgain[i]) return -1;
            DontUseMeAgain[i] = true;
            return A[i].score;
        }
    }
    return -1;
}

void resi(){
    int i,j,k,l,fak,sol;
    sol=0;
    //prvo na gore
    for (i=1; i<=2*N+5; i++){
        memset(DontUseMeAgain,0,sizeof(DontUseMeAgain));
        if (i%2==0) makehitpt_up(h2+100*i); else makehitpt_up(100*(i+1)-h2);
        fak=0;
        for (j=1; j<=HHH; j++){
            l = findmirror(H[j]);
            if (l==-1){
                fak=-1;
                break;
            } else {
                fak += l;
            }
        }
        sol = max(sol,fak);
    }
    //pa na dole
    for (i=1; i<=2*N+5; i++){
        memset(DontUseMeAgain,0,sizeof(DontUseMeAgain));
        if (i%2==0) makehitpt_dn(h2-100*i); else makehitpt_dn(-100*(i-1)-h2);
        fak=0;
        //printf("%d\n",HHH);
        for (j=1; j<=HHH; j++){

            l = findmirror(H[j]);
            //printf("l %d\n",l);
            if (l==-1){
                fak=-1;
                break;
            } else {
                fak += l;
            }
        }
        sol = max(sol,fak);
    }
    printf("%d\n",sol);
}

int main(){
    ucitaj();
    resi();
    return 0;
}