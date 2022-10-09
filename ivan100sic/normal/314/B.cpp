#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int b,d;
char A[105],C[105];
int D[105][105],L1,L2;

int x,y,xp,yp,l,lp,i,j,k,z;
bool fail;

long long zzz;

void sledeci(){
    yp=y+1;
    xp=x+1;
    lp=l;
    if (xp>L1){
        lp++;
        xp=1;
    }
    if (yp>L2){
        yp=1;
        z++;
    }
    int cnt=0;
    while (cnt<102){
        cnt++;
        if (A[xp]==C[yp]) break;
        xp++;
        if (xp>L1){
            xp = 1;
            lp++;
        }
        //printf("%d\n",cnt);
    }
    if (!(cnt<102)) fail=true;
}

int main(){
    scanf("%d%d%s%s",&b,&d,A+1,C+1);
    L1 = strlen(A+1);
    L2 = strlen(C+1);
    x=0;
    y=0;
    l=1;
    while (!fail){
        sledeci();
        //printf("%d %d\n",xp,yp);
        //getchar();
        if (D[xp][yp] != 0) break;
        D[xp][yp] = lp;
        x=xp;
        y=yp;
        l=lp;
    }
    x=xp;
    y=yp;
    l=lp;
    if (fail){
        printf("0\n");
        return 0;
    }
    k = lp - D[xp][yp]; //sto bi po nekoj mojoj proceni moralo da bude lp-1
    zzz = z;
    while (l + k <= b){
        zzz += z;
        l += k;
    }
    if (L1==1 && L2==1 && A[1]==C[1]){
        printf("%d\n",b/d);
        return 0;
    }
    //printf("%d %d %lld %d\n",xp,yp,zzz,k);
    z=0;
    while (true){
        int gud = z + (yp==L2);
        sledeci();
        x=xp;
        y=yp;
        l=lp;
        if (l > b){
            printf("%lld\n",(gud+zzz)/d);
            return 0;
        }
    }
}