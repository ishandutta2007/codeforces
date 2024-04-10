#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[201000];
long long S[201000];
void Solve(){
    int i, j;
    scanf("%d",&n);
    long long res=0, SS = 0;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(i%2==1)SS+=w[i];
    }
    for(i=1;i<=n;i++){
        S[i]=S[i-1];
        if(i%2==1)S[i]+=w[i];
        else S[i]-=w[i];
    }
    long long INF = 1e18;
    long long M[2]={-INF,-INF};
    res=SS;
    for(i=0;i<=n;i++){
        res=max(res,SS + M[i%2] - S[i]);
        if(M[i%2]<S[i])M[i%2]=S[i];
    }
    printf("%lld\n",res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}