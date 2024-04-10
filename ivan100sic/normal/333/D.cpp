#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long BitR[1005][20];
int A[1005][1005];
int R[1005][1005],l,r,m,o,N,i,j,k,M,G;

int popcnt(long long x){
    int r=0;
    while (x!=0){
        x -= x & (-x);
        r++;
    }
    return r;
}

bool probaj(int m){
    int i,j,g,b,pc;
    memset(BitR,0,sizeof(BitR));
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            g = j/64;
            b = j&63;
            if (A[i][j] >= m) BitR[i][g] += (1ll << (long long)b);
        }
    }
    //printf("%lld %lld\n",BitR[1][0],BitR[2][0]);
    long long pr;
    for (i=1; i<=N; i++){
        for (j=i+1; j<=N; j++){
            pc = 0;
            for (k=0; k<=G; k++){
                pr = BitR[i][k] & BitR[j][k];
                pc+=popcnt(pr);
                if (pc>1) return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            scanf("%d",A[i]+j);
        }
    }
    G = M/64 + 1;
    l=0;
    r=1000000000;
    while (l<=r){
        m = (l+r)/2;
        bool ok = probaj(m);
        //printf("%d %c\n",m,ok);
        if (ok){
            o = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    printf("%d\n",o);
    return 0;
}