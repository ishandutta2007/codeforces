#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, Q;
long long F[401000], InvF[401000], Mod = 998244353, C[401000];
char p[201000];
long long Pow(long long a, long long b){
    long long r=1;
    while(b){
        if(b&1)r=r*a%Mod;
        a=a*a%Mod;b>>=1;
    }
    return r;
}
long long Comb(int a, int b){
    return F[a]*InvF[a-b]%Mod*InvF[b]%Mod;
}
void Solve(){
    int i;
    F[0]=1;
    for(i=1;i<=400000;i++)F[i]=F[i-1]*i%Mod;
    InvF[400000] = Pow(F[400000],Mod-2);
    for(i=400000;i>=1;i--)InvF[i-1]=InvF[i]*i%Mod;
    scanf("%d%d",&n,&Q);
    scanf("%s",p);
    int c=0, bb = 0, ww = 0;
    for(i=0;i<n;i++){
        if(p[i]!='?' && i%2){
            p[i]='b'-p[i]+'w';
        }
        if(p[i]=='?')c++;
        if(p[i]=='b')bb++;
        if(p[i]=='w')ww++;
    }
    long long zz=0;
    for(i=0;i<=c;i++){
        if((ww+i)%2 != (n/2)%2)continue;
        zz+=Comb(c,i);
        C[abs((ww+i) - (bb+c-i))/ 2] += Comb(c,i);
    }
    zz%=Mod;

    long long res=0;
    for(i=0;i<=n;i++){
        C[i]%=Mod;
        res=(res+C[i]*i)%Mod;
    }
    res=res*Pow(zz,Mod-2)%Mod;
    res=res*Pow(2,Mod-2)%Mod;
    printf("%lld\n",res);
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}