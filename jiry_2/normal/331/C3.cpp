#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
long long num[20][10][10],f[20][10][10],n,ten[20];
int x[20];
int main(){
    scanf("%I64d",&n); 
    if (n==0){cout<<0<<endl; return 0;}
    if (n<10){cout<<1<<endl; return 0;}
    long long k1=n; int len=0; while (k1){len++; k1=k1/10;}
    ten[0]=1; for (int i=1;i<=len;i++) ten[i]=ten[i-1]*10;
    for (int i=0;i<=9;i++)
        for (int j=0;j<=9;j++)
            if (i<=j){
                num[1][i][j]=j+i; f[1][i][j]=2;
            } else {
                num[1][i][j]=i; f[1][i][j]=1;
            }
    for (int i=2;i<=len;i++)
        for (int j=0;j<=9;j++)
            for (int k=0;k<=9;k++){
                long long k1=ten[i]-10+k,k2=0,k3=0;
                for (int k4=9;k4>=j;k4--){
                    long long k5=num[i-1][k4][k1%10]; k2+=k5; k3+=f[i-1][k4][k1%10]; k1-=k5;
                }
                for (int k4=j-1;k4>=0;k4--){
                    long long k5=num[i-1][j][k1%10]; k2+=k5; k3+=f[i-1][j][k1%10]; k1-=k5;
                }
                num[i][j][k]=k2; f[i][j][k]=k3; //if (i==2) cout<<num[i][j][k]<<" "<<f[i][j][k]<<" "<<j<<" "<<k<<endl;
            }
    long long ans=0;
    while (n>=10){
        len=0; long long k1=n; while (k1) {x[++len]=k1%10; k1/=10;}
        int k2=2; while (k2<=len&&x[k2]==9) k2++; k2--;
        int numm=0; for (int i=k2+1;i<=len;i++) numm=max(numm,x[i]); //cout<<n<<" "<<ans<<" "<<k2<<" "<<numm<<" "<<x[1]<<endl;
        ans+=f[k2][numm][x[1]]; n-=num[k2][numm][x[1]];
    }
    if (n==0) cout<<ans-1<<endl; else cout<<ans+1<<endl; return 0;
}