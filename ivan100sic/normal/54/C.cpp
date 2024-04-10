#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double Prob[1005][1005];
double Ver[1005];
long long L,R,X;
int N,K,KKK,i,j,k;

double probor(double a,double b){
    return 1-((1-a)*(1-b));
}

double proband(double a,double b){
    return a*b;
}

double probnot(double a){
    return 1-a;
}

long long najstep10(long long x){
    long long p=1;
    if (100000000000000000ll <= x && x < 1000000000000000000ll) return 100000000000000000ll;
    if (1000000000000000000ll == x) return 1000000000000000000ll;
    while (10ll*p<=x && 10ll*p>0ll) p*=10ll;
    return p;
}

long long msd(long long x){
    while (x>9) x/=10;
    return x;
}

long long keceva(long long x){
    if (x==0) return 0;
    if (x<10) return 1;
    if (msd(x)!=1){
        return najstep10(x) + keceva(najstep10(x)-1);
    } else {
        return x-najstep10(x) + 1 + keceva(najstep10(x)-1);
    }
}

int main(){
    //printf("%lld\n",najstep10(1000000000000000000ll));
    scanf("%d",&N);
    for (i=1; i<=N; i++){
        scanf("%I64d%I64d",&L,&R);
        X = keceva(R) - keceva(L-1);
        Ver[i] = (double) X / (double)(R-L+1);
        //printf("%.14lf\n",Ver[i]);
    }
    scanf("%d",&K);
    if (K==0) KKK=0; else KKK = ((N*K-1) / 100) + 1;
    Prob[0][0] = 1.00;
    for (i=1; i<=N; i++){
        Prob[i][0] = proband(Prob[i-1][0] , probnot(Ver[i]));
        //printf("%d %d %.14lf\n",i,0,Prob[i][0]);
        for (j=1; j<=N; j++){
            Prob[i][j] = proband(Prob[i-1][j] , probnot(Ver[i])) + proband(Prob[i-1][j-1] , Ver[i]);
            //printf("%d %d %.14lf\n",i,j,Prob[i][j]);
        }
    }
    double sol=0.0;
    for (i=KKK; i<=N; i++) sol = sol + Prob[N][i];
    printf("%.14lf\n",sol);
    return 0;
}