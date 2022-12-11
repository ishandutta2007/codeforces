#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int mo=1e9+7,x[101000],n,L[101000],R[101000],f[101000],two[101000],ten[101000],tot[101000],l[101000],r[101000],size[101000],w[101000];
char ch[101000];
#define sqr(x) (1ll*(x)*(x)%mo)
int solve(){
    int ans=0; size[n+1]=1; int totnum=0;
    for (int i=n;i;i--)
        if (x[i]==4) size[i]=size[i+1]; else size[i]=(two[n-i]+size[i+1])%mo;
    //for (int i=1;i<=n;i++) cout<<size[i]<<" "; cout<<endl;
    w[n+1]=0;
    for (int i=n;i;i--) w[i]=(1ll*w[i+1]+1ll*x[i]*ten[n-i])%mo;
    if (x[n]==7) ans=28; if (x[n]==4) totnum=4; else totnum=11;
    for (int i=n-1;i;i--){
        int num=((1ll*totnum*2-l[n-i]-w[i+1])+mo)%mo;
        if (x[i]==4){
            ans=(ans+1ll*sqr(1ll*ten[n-i]*4%mo)*(size[i+1]-1)%mo+1ll*ten[n-i]*4%mo*num%mo)%mo;
            totnum=(totnum+1ll*ten[n-i]*4%mo*size[i]%mo)%mo;
        } else {
    //      cout<<num<<" "<<totnum<<" "<<l[n-i]<<" "<<w[i+1]<<" "<<ans<<endl;
            ans=(ans+1ll*sqr(1ll*ten[n-i]*7%mo)*(size[i+1]-1)%mo+1ll*ten[n-i]*7%mo*num%mo)%mo;// cout<<ans<<endl;
            num=((1ll*2*tot[n-i]-l[n-i]-r[n-i])%mo+mo)%mo;
    //      cout<<1ll*sqr(1ll*ten[n-i]*4%mo)*(two[n-i]-1)%mo<<" "<<num<<" "<<tot[n-i]<<" "<<l[n-i]<<" "<<r[n-i]<<" "<<1ll*ten[n-i]*4%mo*num<<" "<<f[n-i]<<endl;
            ans=(ans+1ll*sqr(1ll*ten[n-i]*4%mo)*(two[n-i]-1)%mo+1ll*ten[n-i]*4%mo*num%mo+f[n-i])%mo;// cout<<ans<<endl;
            ans=(ans+1ll*L[n-i+1]*R[n-i+1]%mo)%mo;
            totnum=(totnum+1ll*ten[n-i]*7%mo*size[i+1]%mo)%mo;
            totnum=(totnum+tot[n-i]+1ll*ten[n-i]*4%mo*two[n-i]%mo)%mo;
        }
    }
//  cout<<ans<<endl;
    return ans;
}
int main(){
    scanf("%s",ch+1); n=strlen(ch+1); for (int i=1;i<=n;i++) x[i]=ch[i]-'0';
    L[1]=4; R[1]=7; for (int i=2;i<=n;i++){L[i]=(1ll*L[i-1]*10+7)%mo; R[i]=(1ll*R[i-1]*10+4)%mo;} for (int i=1;i<=n;i++) l[i]=ch[i]-'0';
    two[0]=1; for (int i=1;i<=n;i++) two[i]=two[i-1]*2%mo;
    ten[0]=1; for (int i=1;i<=n;i++) ten[i]=1ll*ten[i-1]*10%mo; 
    tot[1]=11; for (int i=2;i<=n;i++) tot[i]=(1ll*tot[i-1]*20%mo+1ll*11*two[i-1])%mo; //cout<<tot[1]<<" "<<two[1]<<" "<<tot[2]<<endl;
    l[1]=4; r[1]=7; for (int i=2;i<=n;i++){l[i]=(1ll*l[i-1]*10+4)%mo; r[i]=(1ll*r[i-1]*10+7)%mo;}
    f[1]=28; 
    for (int i=2;i<=n;i++){
        f[i]=1ll*L[i]*R[i]%mo; long long num=((1ll*2*tot[i-1]-l[i-1]-r[i-1])%mo+mo)%mo;
        f[i]=(f[i]+1ll*sqr(1ll*ten[i-1]*7%mo)*(two[i-1]-1)%mo+1ll*ten[i-1]*7%mo*num+f[i-1])%mo;
        f[i]=(f[i]+1ll*sqr(1ll*ten[i-1]*4%mo)*(two[i-1]-1)%mo+1ll*ten[i-1]*4%mo*num+f[i-1])%mo;
    }
    long long ans=solve(); scanf("%s",ch+1); for (int i=1;i<=n;i++) x[i]=ch[i]-'0'; ans=(solve()-ans+mo)%mo;
    cout<<ans<<endl; return 0;
}