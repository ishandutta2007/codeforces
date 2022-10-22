#include<cstdio>
#include<algorithm>
#include<set>
#define pii pair<int,int>
#define SZ 524288
using namespace std;
int F(long long s){
    int r=0;
    while(s){
        r+=s%10;
        s/=10;
    }
    return r;
}
long long Res[162][10];
void Solve(){
    int n, K;
    scanf("%d%d",&n,&K);
    if(Res[n][K]>8e17)puts("-1");
    else printf("%lld\n",Res[n][K]);
}
void init(){

    int i, j, k, l;
    long long INF = 1e18;
    for(i=1;i<=160;i++)for(j=0;j<=9;j++)Res[i][j]=INF;
    for(i=0;i<1000;i++){
        int s=0;
        for(j=0;j<=9;j++){
            s+=F(i+j);
            if(s<=160) Res[s][j] = min(Res[s][j],1ll*i);
        }
    }
    long long p1=100;
    for(i=1;Res[160][0]==INF;i++){
        for(j=10;j<100;j++){
            for(k=0;k<100;k++){
                long long t = (j+1)*p1-100+k;
                int s=0;
                for(l=0;l<=9;l++){
                    s += F(t+l);
                    if(s<=160) Res[s][l] = min(Res[s][l],t);
                }
            }
        }
        p1*=10;
    }
}
int main(){
    init();
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}