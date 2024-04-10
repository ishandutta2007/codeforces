#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T1[1000005],T2[1000005],x1,y1,x2,y2,h1,h2,m,a1,a2,cyc1,cyc2,tsc1,tsc2;

void findcyc(int poc,int &cyc,int *T,int x,int y,int &tsc){
    memset(T,255,1000005*sizeof(int));
    T[poc] = 0;
    int t=0;
    while (1){
        poc = (1ll*poc*x+y) % m;
        t++;
        if (T[poc]!=-1){
            cyc = t - T[poc];
            tsc = T[poc];
            return;
        } else {
            T[poc] = t;
        }
    }
}

int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}

int main(){
    scanf("%d",&m);
    scanf("%d%d",&h1,&a1);
    scanf("%d%d",&x1,&y1);
    scanf("%d%d",&h2,&a2);
    scanf("%d%d",&x2,&y2);
    findcyc(h1,cyc1,T1,x1,y1,tsc1);
    findcyc(h2,cyc2,T2,x2,y2,tsc2);
    if (T1[a1]==-1 || T2[a2]==-1){
        printf("-1\n");
        return 0;
    }
    long long t1=T1[a1];
    long long t2=T2[a2];
    for (int i=1; i<=6000005; i++){
        if (t1<t2) t1+=(t2-t1+cyc1-1)/cyc1*cyc1*(T1[a1]>=tsc1?1:0); else
        if (t1>t2) t2+=(t1-t2+cyc2-1)/cyc2*cyc2*(T2[a2]>=tsc2?1:0); else {
            printf("%lld\n",t1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}