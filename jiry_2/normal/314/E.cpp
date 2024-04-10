#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char ch[110000];
unsigned int f[110000];
int n,pd[110000],now;
int main(){
    scanf("%d",&n); scanf("%s",ch+1); if (n%2==1){cout<<0<<endl; return 0;}
    for (int i=1;i<=n;i++) if (ch[i]!='?') pd[i]=1;
    f[0]=1; int k=n/2,now=0;
    for (int i=1;i<=n;i++){
        if (pd[i]){
            int k1; now++;
            if (i%2==k%2) k1=k; else k1=k-1;
            for (int j=k1;j>=1;j--)f[j]=f[j-1]; f[0]=0;
        } else {
            int k1;
            if ((i&1)==0){f[0]=f[1]; k1=2;} else k1=1;
            for (int i=k1;i<=k;i+=2) f[i]=f[i+1]+f[i-1];
        }
    }
    now=k-now; for (int i=1;i<=now;i++) f[0]=f[0]*25;
    cout<<f[0]<<endl; return 0;
}